#include "TexturedModel.h"

TexturedModel::TexturedModel(Model model, ModelTexture texture)
	: model(model)
	, texture(texture)
{
}

Model TexturedModel::GetModel() const
{
	return model;
}

ModelTexture TexturedModel::GetTexture() const
{
	return texture;
}
