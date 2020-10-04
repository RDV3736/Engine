
#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include "settings.h"
#include "gameMain.h"
#include "componentSystem.h"
#include "RdTransform.h"
#include "BoxCollider2D.h"
int main(int argc, char* argv[])
{
	SDL_Window* window;
	gameL L;
	SDL_Renderer* renderer;
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("2D Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings::windowWidth, settings::windowHeight, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event msg;

	if (settings::devConsole == true)
	{
		AllocConsole();
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	}


	

	RdEntityManager::getInstance()->init();
	RdEntityManager::getInstance()->start(renderer);
	L.start(renderer);
	while (1)
	{
		
		
		SDL_PollEvent(&msg); 

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		L.rendermain(renderer);

		SDL_RenderPresent(renderer);
		
		
		switch (msg.type)
		{
			// maybe add some frametime here
		case SDL_QUIT:
			SDL_Quit();
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			return 1;
		}
	}

	SDL_Quit();
	return -1;
}