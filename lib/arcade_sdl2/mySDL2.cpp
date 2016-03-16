//
// mySDL2.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:16:43 2016 Erwan Dupard
// Last update Wed Mar 16 13:50:30 2016 Erwan Dupard
//

#include "mySDL2.hh"

mySDL2::mySDL2()
{
  this->_name = "libsdl2";
  this->_window = NULL;
}

const std::string	&mySDL2::getName() const
{
  return (this->_name);
}

void			mySDL2::initDisplay()
{
  if (SDL_Init( SDL_INIT_VIDEO ) >= 0)
    {
      this->_window = SDL_CreateWindow("SDLWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_X, SCREEN_Y, SDL_WINDOW_SHOWN);
      if (this->_window)
  	{
	  this->_screen = SDL_GetWindowSurface(this->_window);
  	  SDL_FillRect(this->_screen, NULL, SDL_MapRGB(this->_screen->format, 0xFF, 0xFF, 0xFF));
  	  SDL_UpdateWindowSurface(this->_window);
  	}
    }
}

void			mySDL2::closeDisplay()
{
  SDL_DestroyWindow(this->_window);
  SDL_Quit();
}

void			mySDL2::renderTitleScreen(const std::string &gameTitle, const std::string &Instructions)
{
  (void)gameTitle;
  (void)Instructions;
}

void			mySDL2::renderMap(const game::Map &map)
{
  (void)map;
}

void			mySDL2::renderMenu(MenuState menuState)
{
  (void)menuState;
}

char			mySDL2::getLastInput()
{
  SDL_Event	        e;

  while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
	return (0);
      if (e.type == SDL_KEYDOWN)
	{
	  game::Position	p(5, 5);

	  this->writeTile(p, 0x00000000);
	  return (e.key.keysym.sym);
	}
    }
  return (UNDEFINED_KEY_INPUT);
}

void			mySDL2::writeTile(const game::Position &position, Uint32 color)
{
  Uint32		*pixels = (Uint32 *)this->_screen->pixels;
  Uint32		start = ((SCREEN_Y / position.y) * this->_screen->w) + (SCREEN_X / position.x);
  Uint32		save = start;
  Uint32		i;

  while (start <= save + (TILE_SIZE * SCREEN_X))
    {
      i = start;
      while (i <= (start + TILE_SIZE))
	{
	  std::cout << "Writing at : " << i << std::endl;
	  pixels[i] = color;
	  ++i;
	}
      start += SCREEN_X;
    }
  
}

extern "C" IDisplay	*create()
{
  return (new mySDL2());
}
