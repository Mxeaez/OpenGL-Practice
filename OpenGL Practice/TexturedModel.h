#pragma once
#include "Model.h"
#include "ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel(Model model, ModelTexture texture);

	Model GetModel() const;
	ModelTexture GetTexture() const;

private:
	Model model;
	ModelTexture texture;
};