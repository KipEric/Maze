#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <SDL2/SDL.h>

#define MAP_NUM_COLS 20
#define MAP_NUM_ROWS 16
#define map_x 16
#define map_y 20
#define map_s 20
#define MAP_SCALE 0.25
#define gun_scale 0.25
#define PI 3.14159265
#define FOV (PI / 3)
#define num_enemy 5
#define num_rays 60

int x, y;

typedef struct {
	double x;
	double y;
} Point;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;
SDL_Texture* screen;

Point playerPos;
SDL_Surface* w_surf;

int runGame(void);
Point distanceToWall(Point playerPosition, double playerEyeAngle);
void loadMap(Point* playerPosition, double *playerEyeAngle);
void whereIsThePlayer(SDL_Renderer *renderer);
void playerMovementControl(double horizontal_change, double vertical_change);
void whereIsPlayer(SDL_Renderer *renderer);
bool handleAllEvents(SDL_Event);
bool mouseEvents(SDL_Event mouse_event);
void drawScreen(SDL_Renderer* renderer, SDL_Texture* screen);
void display_player(SDL_Renderer *renderer);
void playerWeapon();

#endif /* HEADER_H */
