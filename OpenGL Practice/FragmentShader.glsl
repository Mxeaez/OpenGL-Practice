#version 330 core

in vec2 pass_Texture;
in vec3 surfaceNormal;
in vec3 vectorToLight;

uniform sampler2D modelTexture;
uniform vec3 lightColour;

out vec4 outColour;

void main()
{
	vec3 unitSurfaceNormal = normalize(surfaceNormal);
	vec3 unitVectorToLight = normalize(vectorToLight);
	float dotProduct = dot(unitSurfaceNormal, unitVectorToLight);
	float brightness = max(dotProduct, 0.0f);
	vec3 diffuse = brightness * lightColour;
	
	outColour = vec4(diffuse, 1.0f) * texture(modelTexture, pass_Texture);
}