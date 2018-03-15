#pragma once

class ModelTexture
{
public:

	ModelTexture(unsigned int textureID, float reflectivity = 1.0f, float damper = 10.0f);
	unsigned int GetTextureID() const;

	float GetReflectivity() const;
	void SetReflectivity(float newReflectivity);

	float GetDamper() const;
	void SetDamper(float newDamper);

private:
	unsigned int textureID;
	float reflectivity;
	float damper;
};