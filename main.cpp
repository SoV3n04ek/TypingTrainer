#include <SFML/Audio.hpp>
#include <Windows.h>
#include "Game.hpp"

int main()
{
	// for random
	srand(time(0));
	//Window variables
	int ticks = 0;
	FreeConsole(); //Hide console

	// game
	Game game;
	game.start();
}