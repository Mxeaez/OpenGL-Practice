#pragma once
#include "WindowManager.h"
#include "Loader.h"
#include "Renderer.h"

class Game
{
public:

	Game();

	void RunMainGameLoop();

private:
	Loader loader;
	Renderer renderer;
	WindowManager window;
};