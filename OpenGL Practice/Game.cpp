#include "Game.h"
#include "Shader.h"
#include "Entity.h";
#include "Camera.h"

Game::Game()
{
}

void Game::RunMainGameLoop()
{

	std::vector<float> vertices = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f
	};

	std::vector<unsigned int> indices = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22
	};

	std::vector<float> textureCoords = {
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0
	};

	Shader shader("VertexShader.glsl", "FragmentShader.glsl");
	shader.Bind();

	Model model = loader.LoadToVAO(vertices, textureCoords, indices);
	ModelTexture texture = loader.LoadTexture("res/erica.png");
	TexturedModel texturedModel(model, texture);

	Entity entity(texturedModel, glm::vec3(0.0f, 0, -5.0f), 0, 0, 0, 1);

	Camera camera;

	sf::Clock clock;

	while (true)
	{
		window.Clear();

		camera.Move();

		entity.IncreaseRotation(glm::sin(clock.getElapsedTime().asSeconds()) * 0.02f, glm::sin(clock.getElapsedTime().asSeconds()) * 0.02f, 0);

		shader.LoadViewMatrix(camera);

		renderer.Render(entity, shader);
		glEnableVertexAttribArray(0);

		window.PollEvents();
		window.Display();
	}
}
