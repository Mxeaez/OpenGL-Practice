#include "ModelTexture.h"

ModelTexture::ModelTexture(unsigned int textureID)
	: textureID(textureID)
{
}

unsigned int ModelTexture::GetTextureID() const
{
	return textureID;
}
