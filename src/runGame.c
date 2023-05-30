#include "../header/header.h"
#include <stdio.h>
#include <SDL2/SDL_image.h>

/**
 * loopDisplay - display window
 * Description: Window initialization
 *
 * Return: void
 */
void loopDisplay()
{
	bool quit = false;
	const int FPS = 60;
	Uint32 framestart, frameTime, delayTime;
	unsigned int time;

	while (!quit)
	{
		framestart = SDL_GetTicks();
		quit = handleAllEvents(e);
		drawScreen(renderer, screen);
		playerWeapon();
		frameTime = SDL_GetTicks() - framestart;
		delayTime = 1000 / FPS - frameTime;
		time = 1000;
		if (delayTime > time / FPS)
			delayTime = 0;
		SDL_Delay(delayTime);
	}
}

/**
 * runGame - Function that run the game
 *
 * Description:
 *
 * Return: int
 */
int runGame(void)
{
	double playerA = 0.0;
	const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	window = SDL_CreateWindow("Maze Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	renderer =SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
        	SDL_Quit();
        	return 1;
	}
	screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (screen == NULL)	
	{
		fprintf(stderr, "Failed to create screen texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(renderer);
        	SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		fprintf(stderr, "Failed to initialize SDL_image.\n");
	 	SDL_DestroyTexture(screen);
        	SDL_DestroyRenderer(renderer);
        	SDL_DestroyWindow(window);
        	SDL_Quit();
       		return 1;
	}
	SDL_SetRelativeMouseMode(SDL_TRUE);
	loadMap(&playerPos, &playerA);
	
	w_surf = IMG_Load("../images/wall3.bmp");
	if (w_surf == NULL)
	{
		fprintf(stderr, "Failed to load wall3.bmp: %s\n", SDL_GetError());
		SDL_DestroyTexture(screen);
        	SDL_DestroyRenderer(renderer);
        	SDL_DestroyWindow(window);
        	SDL_Quit();
        	return 1;
	}

	loopDisplay();

	SDL_DestroyTexture(screen);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 1;
}
