#include "Game.h"
#include "Shader.h"
#include "Entity.h"
#include "Camera.h"
#include "ObjLoader.h"
#include "Light.h"

Game::Game()
{
}

void Game::RunMainGameLoop()
{
	Shader shader("VertexShader.glsl", "FragmentShader.glsl");

	Loader loader;
	Renderer renderer(shader);

	ObjLoader objLoader;
	Model model = objLoader.LoadObjToModel("res/stall.obj", loader);
	ModelTexture texture = loader.LoadTexture("res/stallTexture.png");
	TexturedModel texturedModel(model, texture);

	Entity entity(texturedModel, glm::vec3(0.0f, -5.0f, -25.0), 0, 0, 0, 1);

	Camera camera;

	Light light(glm::vec3(0.0f, 0.0f, -20.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	shader.Start();
	while (true)
	{
		renderer.Prepare();

		camera.Move();

		entity.IncreaseRotation(0, 0.02f, 0);

		shader.LoadLight(light);
		shader.LoadViewMatrix(camera);
		renderer.Render(entity, shader);


		window.PollEvents();
		window.Display();
	}
}
