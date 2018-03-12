#include "Game.h"
#include "Shader.h"
#include "Entity.h";

Game::Game()
{
}

void Game::RunMainGameLoop()
{

	std::vector<float> vertices = {
		-0.5, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		0.5, 0.5, 0.0,
		0.5, -0.5, 0.0
	};

	std::vector<unsigned int> indices = {
		0, 1, 2,
		1, 2, 3
	};

	std::vector<float> textureCoords = {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	Shader shader("VertexShader.glsl", "FragmentShader.glsl");
	shader.Bind();

	Model model = loader.LoadToVAO(vertices, textureCoords, indices);
	ModelTexture texture = loader.LoadTexture("res/erica.png");
	TexturedModel texturedModel(model, texture);

	Entity entity(texturedModel, glm::vec3(-1.0f, 0, 0), 0, 0, 0, 1);

	while (true)
	{
		window.Clear();

		renderer.Render(entity, shader);
		glEnableVertexAttribArray(0);

		window.PollEvents();
		window.Display();
	}
}
