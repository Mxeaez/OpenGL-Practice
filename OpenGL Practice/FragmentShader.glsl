#version 330 core

in vec2 outTexture;
in vec3 colour;

uniform sampler2D ourTexture;

out vec4 outColour;

void main()
{
	outColour = texture(ourTexture, outTexture);
}