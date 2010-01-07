#include <iostream>

#include <SDL.h>
#include <sge.h>

#include "feng.hpp"

using namespace std;

int main(int argc, char *argv[]){
	unsigned const int
		MAXX = 800,
		MAXY = 400,
		CENTERX = MAXX / 2,
		CENTERY = MAXY / 2;

	SDL_Surface * screen = NULL;
	SDL_Event event;
	Uint8 * keystate = NULL;
	sge_TTFont * font = NULL;

/* SDL init */
	atexit(SDL_Quit);
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		cerr << "Unable to init SDL: " << SDL_GetError() << endl;
		exit(1);
	}
	if (sge_TTF_Init()){
		cerr << "TT error: " << SDL_GetError() << endl;
		exit(1);
	}
	font = sge_TTF_OpenFont("Courier_New_Bold.ttf", 9);
	if (!font){
		cerr << "TT error: " << SDL_GetError() << endl;
		exit(1);
	}
	keystate = SDL_GetKeyState(NULL);
	if (!keystate){
		cerr << "SDL error: unable to init keystate" << endl;
		exit(1);
	}
	screen = SDL_SetVideoMode(MAXX,MAXY,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_HWACCEL);
	if(!screen){
		cerr << "Unable to set video: " << SDL_GetError() << endl;
		exit(1);
	}
	sge_TTF_AA_Alpha();
	sge_Update_OFF();
	SDL_WM_SetCaption("fsim","fsim");

	real dt = .01;
	particle cosa;
	camera cam;
	cam.resolution[0] = MAXX;
	cam.resolution[1] = MAXY;
	R3 shadow;
	R3 pos;
	R3 force;
	while (true){
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				exit(0);
		if (keystate[SDLK_ESCAPE])
			for(int i = 0; i < 3; i++)
				cosa.position[i] = cosa.velocity[i] = 0;
		force[1] = keystate[SDLK_DOWN] - keystate[SDLK_UP];
		force[0] = keystate[SDLK_RIGHT] - keystate[SDLK_LEFT];
		force[2] = keystate[SDLK_k] - keystate[SDLK_m] - .5;
		cosa.velocity += force * dt;
		cosa.position += cosa.velocity * dt;
		if (cosa.position[2] < 0){
			cosa.position[2] *= -1;
			cosa.velocity[2] *= -1;
		}
		shadow = cosa.position;
		shadow[2] = 0;
//		cam.position = cosa.position;
		shadow = cam.watch(shadow);
		pos = cam.watch(cosa.position);
		SDL_FillRect(screen, NULL, 0x00c0d8ff);
		sge_AAFilledCircle(screen, shadow[0], shadow[1], 8, 0x007f7f7f);
		sge_AALine(screen, shadow[0], shadow[1], pos[0], pos[1], 0x00000000);
		sge_AAFilledCircle(screen, pos[0], pos[1], 8, 0x00ff0000);
		SDL_Flip(screen);
		sge_Delay(dt * 1e3);
	}

	return 0;
}
