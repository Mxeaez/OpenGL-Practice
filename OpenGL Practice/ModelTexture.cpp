#include "ModelTexture.h"

ModelTexture::ModelTexture(unsigned int textureID, float reflectivity, float damper)
	: textureID(textureID)
	, reflectivity(reflectivity)
	, damper(damper)
{
}

unsigned int ModelTexture::GetTextureID() const
{
	return textureID;
}

float ModelTexture::GetReflectivity() const
{
	return reflectivity;
}

void ModelTexture::SetReflectivity(float newReflectivity)
{
	reflectivity = newReflectivity;
}

float ModelTexture::GetDamper() const
{
	return damper;
}

void ModelTexture::SetDamper(float newDamper)
{
	damper = newDamper;
}
