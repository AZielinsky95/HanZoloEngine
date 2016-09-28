#include "Errors.h"
#include <cstdlib>
#include <iostream>
#include <SDL.h>

void fatalError(std::string error)
{
	std::cout << error << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(69);
}

