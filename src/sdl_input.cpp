
// SDL2
#include <SDL2/SDL.h>

// LOCAL
#include "sdl_input.h"



SDLInput::SDLInput() {}

SDLInput::~SDLInput() {}


GameCommand SDLInput::GetCommand()
{
	SDL_Event e;
	while(SDL_PollEvent(&e) == 1)
	{
		if (e.type == SDL_QUIT)
		{
			return GameCommand::QUIT;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			return GameCommand::DOWN;
		}
		
		switch (e.key.keysym.sym)
		{
    case SDLK_SPACE:
      return GameCommand::SPACE;
    case SDLK_LEFT:
      return GameCommand::LEFT;
    case SDLK_RIGHT:
      return GameCommand::RIGHT;
    default:
      return GameCommand::NIL;
		}
	}
	return GameCommand::NIL;
}


void SDLInput::Init()
{
	SDL_FlushEvent(SDL_KEYDOWN);  
}

