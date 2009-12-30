#include <iostream>

#include <SDL.h>
#include <sge.h>

#include "feng.hpp"

using namespace std;

int main(int argc, char *argv[]){
	unsigned const int
		MAXX = 800,
		MAXY = 600,
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

	return 0;
}
