#version 410 core

in vec3 textureCoordinates;
out vec4 color;

uniform samplerCube skybox;
uniform float grey;

void main()
{
	
	if (grey == 1.0f)
	{
	 color = vec4(0.5f, 0.5f, 0.5f, 1.0f);
	}
	else
	{
		color = texture(skybox, textureCoordinates);
	}
}