#pragma once

class ModelTexture
{
public:

	ModelTexture(unsigned int textureID);
	unsigned int GetTextureID() const;

private:
	unsigned int textureID;
};