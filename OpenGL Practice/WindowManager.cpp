#include "WindowManager.h"
#include <GL\glew.h>
#include <assert.h>

WindowManager::WindowManager()
{

	sf::ContextSettings context;
	context.minorVersion = 3;
	context.majorVersion = 3;
	context.depthBits = 24;
	context.attributeFlags = sf::ContextSettings::Core;

	window.create(sf::VideoMode(WIDTH, HEIGHT), "BrodyScape", sf::Style::Close, context);

	bool glew = glewInit();

	assert(glew == GLEW_OK);

	glViewport(0, 0, WIDTH, HEIGHT);

	glEnable(GL_TEXTURE_2D);
}

void WindowManager::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool WindowManager::IsOpen()
{
	return window.isOpen();
}

void WindowManager::Close()
{
	window.close();
}

void WindowManager::Display()
{
	window.display();
}

void WindowManager::PollEvents()
{
	sf::Event e;

	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}