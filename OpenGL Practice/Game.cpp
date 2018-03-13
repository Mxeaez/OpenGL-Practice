#include "Game.h"
#include "Shader.h"
#include "Entity.h";
#include "Camera.h"
#include "ObjLoader.h"

Game::Game()
{
}

void Game::RunMainGameLoop()
{
	Shader shader("VertexShader.glsl", "FragmentShader.glsl");
	shader.Bind();

	ObjLoader objLoader;

	Model model = objLoader.LoadObjToModel("res/stall.obj", loader);

	ModelTexture texture = loader.LoadTexture("res/stallTexture.png");
	TexturedModel texturedModel(model, texture);

	Entity entity(texturedModel, glm::vec3(0.0f, 0, -25.0), 0, 0, 0, 1);

	Camera camera;

	sf::Clock clock;

	while (true)
	{
		window.Clear();

		camera.Move();

		entity.IncreaseRotation(0, 0.002f, 0);

		shader.LoadViewMatrix(camera);

		renderer.Render(entity, shader);
		glEnableVertexAttribArray(0);

		window.PollEvents();
		window.Display();
	}
}
