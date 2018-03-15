#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture;
layout(location = 2) in vec3 normal;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform vec3 lightPosition;

out vec2 pass_Texture;
out vec3 surfaceNormal;
out vec3 vectorToLight;
out vec3 vectorToCamera;

void main()
{
    vec4 worldPosition = transformationMatrix * vec4(position, 1.0f);
	gl_Position = projectionMatrix * viewMatrix * worldPosition;

	pass_Texture = texture;

	surfaceNormal = (transformationMatrix * vec4(normal, 0.0f)).xyz;
	vectorToLight = lightPosition - worldPosition.xyz;

	vectorToCamera = (inverse(viewMatrix) * vec4(0.0f, 0.0f, 0.0f, 1.0f)).xyz;

}