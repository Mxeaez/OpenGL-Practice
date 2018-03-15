#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class WindowManager
{
public:

	WindowManager();
	WindowManager(const WindowManager& rhs) = delete;
	WindowManager& operator=(const WindowManager& rhs) = delete;

	bool IsOpen();
	void Close();
	void Display();
	void PollEvents();

public:
	static constexpr int WIDTH = 800;
	static constexpr int HEIGHT = 600;

private:
	sf::Window window;
};