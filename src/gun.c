#include "../header/header.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * playerWeapon - Function to draw a weapon
 *
 * Description: this where a player gun is design
 *
 * Return: void
 */
void playerWeapon(void)
{
	const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;
	SDL_Texture *texture = NULL;
	SDL_Rect gun;
	int w, h;
	SDL_Surface * surf = IMG_Load("./image/gun1.png");

	if (surf)
	{
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 255, 255));
		texture = SDL_CreateTextureFromSurface(renderer, surf);
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		gun.w = w * gun_scale, gun.h = h * gun_scale;
		gun.x = (SCREEN_WIDTH - gun.w) / 2;
		gun.y = (SCREEN_HEIGHT - gun.h) + 10;

		if (texture)
			SDL_RenderCopy(renderer, texture, NULL, &gun);
		else
			printf("Unable to create texture\n");

		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
	else
		printf("Unable to create a surface\n");
}
