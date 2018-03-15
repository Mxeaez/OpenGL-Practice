#pragma once
#include "Entity.h"
#include "Shader.h"

class Renderer
{
public:

	Renderer(Shader shader);

	void Render(Entity entity, Shader shader);
	void Prepare();

};