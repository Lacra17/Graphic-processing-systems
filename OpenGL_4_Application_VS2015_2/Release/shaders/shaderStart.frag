#version 410 core

struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  

struct PointLight {    
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
}; 

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

 
#define NR_POINT_LIGHTS 16
 
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;
uniform DirLight dirLight;

in vec3 normal;
in vec4 fragPosEye;
in vec2 fragTexCoords;
in vec4 fragPosLightSpace;

out vec4 color;

//lighting
uniform	mat3 normalMatrix;

uniform	vec3 lightDir;
uniform	vec3 lightColor;
uniform mat3 lightDirMatrix;
uniform vec3 viewPos;
in vec3 lightPosEye[10];
uniform float fog;
uniform float day;

uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;
uniform samplerCube skybox;
uniform sampler2D shadowMap;

vec3 lightDirN;
float ambientStrength = 0.4f;
float specularStrength = 0.5f;
float shininess = 32.0f;

float constant = 1.0f;
float linear = 0.0045f;
float quadratic = 0.0075f; 

vec3 ambientFinal;
vec3 diffuseFinal;
vec3 specularFinal;


void CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    // Diffuse shading

    float diff = max(dot(normal, lightDir), 0.0);

    // Specular shading

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);

    // Combine results

    vec3 ambient  = light.ambient  * vec3(texture(diffuseTexture, fragTexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(diffuseTexture, fragTexCoords));
    vec3 specular = light.specular * spec * vec3(texture(specularTexture, fragTexCoords));

	ambientFinal+=ambient;
	diffuseFinal+=diffuse;
	specularFinal+=specular;

}  

// Calculates the color when using a point light.
void CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // Attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0f / (constant + linear * distance + 
  			     quadratic * (distance * distance));    
    // Combine results
    vec3 ambient  = light.ambient  * vec3(texture(diffuseTexture, fragTexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(diffuseTexture, fragTexCoords));
    vec3 specular = light.specular * spec * vec3(texture(specularTexture, fragTexCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

	ambientFinal+=ambient;
	diffuseFinal+=diffuse;
	specularFinal+=specular;
} 

// Calculates the color when using a spot light.
void CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    // Diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // Specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (constant + linear * distance + quadratic * (distance * distance));    
    // Spotlight intensity
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    // Combine results
    vec3 ambient = light.ambient * vec3(texture(diffuseTexture, fragTexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(diffuseTexture, fragTexCoords));
    vec3 specular = light.specular * spec * vec3(texture(specularTexture, fragTexCoords));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;

	ambientFinal+=ambient;
	diffuseFinal+=diffuse;
	specularFinal+=specular;
}

float computeShadow()
{	
	// perform perspective divide
    vec3 normalizedCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    if(normalizedCoords.z > 1.0f)
        return 0.0f;
    // Transform to [0,1] range
    normalizedCoords = normalizedCoords * 0.5f + 0.5f;
    // Get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap, normalizedCoords.xy).r;    
    // Get depth of current fragment from light's perspective
    float currentDepth = normalizedCoords.z;
    // Check whether current frag pos is in shadow
    float bias = 0.005f;
    float shadow = currentDepth - bias> closestDepth  ? 1.0f : 0.0f;

    return shadow;	
}

float computeFog()
{
    float fogDensity = 0.05f;
    float fragmentDistance = length(fragPosEye);
    float fogFactor = exp(-pow(fragmentDistance * fogDensity,2));
    
    return clamp(fogFactor, 0.01, 1.0f);
}


void main() 
{
	/*vec3 result = vec3(0.0f);

	for (int i=0; i<8; i++)
	{
		result += computeLight(lightPosEye[i]);
	}
    fColor = vec4(result, 1.0f);
	*/
	
	vec3 viewDirectionN = normalize(vec3(fragPosEye));
	vec3 normalN = normalize(normal);
	vec3 reflection = reflect(viewDirectionN, normalN);
	vec3 colorFromSkybox = vec3(texture(skybox, reflection));
	
    // Properties
    vec3 norm = normalize(normalMatrix * normal);
    vec3 viewDir = normalize(viewPos - fragPosEye.xyz);


	/*
    // Phase 1: Directional lighting
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    // Phase 2: Point lights
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, fragPosEye.xyz, viewDir);    
    // Phase 3: Spot light
    result += CalcSpotLight(spotLight, norm, fragPosEye.xyz, viewDir);    


	*/
	// Phase 1: Directional lighting
	CalcDirLight(dirLight, norm, viewDir);
	if (day == 0.0f)
	{
		// Phase 2: Point lights
	 	for(int i = 0; i < NR_POINT_LIGHTS; i++)
        	CalcPointLight(pointLights[i], norm, fragPosEye.xyz, viewDir); 
	}
	// Phase 3: Spot light
	CalcSpotLight(spotLight, norm, fragPosEye.xyz, viewDir);    


	float shadow =  computeShadow();
	
	//modulate with shadow
	vec3 colorForShadows = min((ambientFinal + (1.0f - shadow)*diffuseFinal) + (1.0f - shadow)*specularFinal, 1.0f);
    
	float fogFactor = computeFog();
	vec4 fogColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);

	if (fog == 1.0f)
	{
		color = vec4(colorForShadows, 1.0f);
		color = fogColor * (1-fogFactor) + color * fogFactor;
	}
	else
	{
		color = vec4(colorForShadows, 1.0f);
	}
}