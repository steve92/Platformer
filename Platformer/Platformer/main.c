#include <SDL.h>
#include <SDL_image.h>
typedef enum { false, true } bool;

const int WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 768;

int main()
{
	SDL_Surface *screen;
	SDL_Event event;
	bool running = true;
	SDL_Rect source;
	SDL_Rect destination;
	SDL_Surface* image;

	SDL_Init( SDL_INIT_EVERYTHING );

	if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
		exit(1);

	screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
	if(screen == NULL)
		exit(1);

	image = IMG_Load("..\\Images\\file.png");
	source.x = 0;
	source.y = 0;
	source.w = 283;
	source.h = 648;
	destination.x = 0;
	destination.y = 0;

	while(running)
	{
		if (SDL_PollEvent(&event))
		{ 
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		} 

		SDL_BlitSurface(image, &source, screen, &destination);

		SDL_Flip(screen);
	}

	SDL_Quit();
	return 0;    
}
