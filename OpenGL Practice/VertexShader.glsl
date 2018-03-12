#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture;

uniform mat4 transformationMatrix;

out vec2 outTexture;
out vec3 colour;

void main()
{
	gl_Position = transformationMatrix * vec4(position, 1.0f);
	colour = vec3(0.0f, 0.5f, 1.0f);
	outTexture = texture;
}