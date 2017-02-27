#version 410 core

layout(location=0) in vec3 vPosition;
layout(location=1) in vec3 vNormal;
layout(location=2) in vec2 vTexCoords;

out vec3 normal;
out vec4 fragPosEye;
out vec2 fragTexCoords;
out vec4 fragPosLightSpace;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
out vec3 lightPosEye;
uniform mat4 lightSpaceTrMatrix;

void main()
{
	lightPosEye = vec3(view *vec4(lightPos, 1.0f));
    gl_Position = projection * view *  model * vec4(vPosition, 1.0f);
    fragPosEye = model * vec4(vPosition, 1.0f);
	normal = vNormal;  
    fragTexCoords = vTexCoords;
	fragPosLightSpace = lightSpaceTrMatrix * model * vec4(vPosition, 1.0f);
} 