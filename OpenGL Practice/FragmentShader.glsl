#version 330 core

in vec2 pass_Texture;
in vec3 surfaceNormal;
in vec3 vectorToLight;
in vec3 vectorToCamera;

uniform sampler2D modelTexture;
uniform vec3 lightColour;
uniform float reflectivity;
uniform float damper;

out vec4 outColour;

void main()
{
	vec3 unitSurfaceNormal = normalize(surfaceNormal);
	vec3 unitVectorToLight = normalize(vectorToLight);
	float dotProduct = dot(unitSurfaceNormal, unitVectorToLight);
	float brightness = max(dotProduct, 0.1f);
	vec3 diffuse = brightness * lightColour;

	vec3 unitVectorToCamera = normalize(vectorToCamera);
	vec3 unitLightDirection = -unitVectorToLight;
	vec3 lightReflection = reflect(unitLightDirection, unitSurfaceNormal);
	float specularFactor = dot(unitVectorToCamera, lightReflection);
	specularFactor = max(specularFactor, 0.0f);
	float dampening = pow(specularFactor, damper);
	vec3 finalSpecular = dampening * reflectivity * lightColour;
	
	outColour = vec4(diffuse, 1.0f) * texture(modelTexture, pass_Texture) + vec4(finalSpecular, 1.0f);
}