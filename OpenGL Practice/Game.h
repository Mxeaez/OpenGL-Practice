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
	WindowManager window;
};