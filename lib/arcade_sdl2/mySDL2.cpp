//
// mySDL2.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:16:43 2016 Erwan Dupard
// Last update Fri Apr  1 18:13:48 2016 Erwan Dupard
//

#include "mySDL2.hh"
#include <unistd.h>

mySDL2::mySDL2()
{
  this->_name = "libsdl2";
  this->_window = NULL;
  this->_screen = NULL;
}

void			mySDL2::initDisplay()
{
  if (SDL_Init(SDL_INIT_VIDEO) >= 0)
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
  // SDL_DestroyRenderer(this->_renderer);
  // SDL_DestroyWindow(this->_window);
  SDL_Quit();
}

void			mySDL2::renderTitleScreen(const std::string &gameTitle, const std::string &instructions)
{
  (void)gameTitle;
  (void)instructions;
}

void			mySDL2::renderMap(const game::Map &map)
{
  game::Position	tileSize(SCREEN_X / map.getWidth(), SCREEN_Y / map.getHeight());
  unsigned int		i = 0;
  const game::Tile	*tiles = map.getTiles();
  game::Position	p(0, 0);

  while (i < map.getWidth() * map.getHeight())
    {
      p.y = (i == 0 ? 0 : i / map.getWidth());
      p.x = i - (p.y * map.getWidth());
      switch (tiles[i])
  	{
  	case game::Tile::SNAKE:
  	  this->writeTile(p, tileSize, 0x000f9d58);
	  break;
	case game::Tile::POWERUP:
	  this->writeTile(p, tileSize, 0x006d0a3a);
  	  break;
	case game::Tile::OBSTACLE:
	  this->writeTile(p, tileSize, 0x00000000);
  	  break;
	case game::Tile::PACMAN:
	  this->writeTile(p, tileSize, 0x00FFFF00);
  	  break;
	case game::Tile::GHOST:
	  this->writeTile(p, tileSize, 0x00FF0000);
  	  break;
	case game::Tile::HUNTED_GHOST:
	  this->writeTile(p, tileSize, 0x000000FF);
  	  break;
  	default:
  	  this->writeTile(p, tileSize, 0x00FFFFFF);
	  break;
  	}
      ++i;
    }
  this->updateSurface();
}

void			mySDL2::renderMenu(const MenuState &menuState)
{
  (void)menuState;
}

char			mySDL2::getLastInput()
{
  SDL_Event	        e;
  SDL_Event		keyEvent;
  bool			foundKey = false;

  while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
	return (0);
      if (e.type == SDL_KEYDOWN)
	{
	  keyEvent = e;
	  foundKey = true;
	}
    }
  if (foundKey == true)
    return (keyEvent.key.keysym.sym);
  return (UNDEFINED_KEY_INPUT);
}

void			mySDL2::writeTile(const game::Position &position, const game::Position &size, Uint32 color)
{
  Uint32		*pixels = (Uint32 *)this->_screen->pixels;
  Uint32		start = 0;
  Uint32		save;
  Uint32		i;
  
  start = ((SCREEN_X * position.y * size.y) + (size.x * position.x));
  save = start;
  SDL_LockSurface(this->_screen);
  if (pixels[start + (SCREEN_X * 2)] != color)
    {
      while (start <= (save + (size.y * SCREEN_X)))
      	{
      	  i = start;
      	  while (i < (start + size.x))
      	    {
      	      pixels[i] = color;
      	      ++i;
      	    }
      	  start += SCREEN_X;
      	}
    }
  SDL_UnlockSurface(this->_screen);
}

void			mySDL2::cleanScreen()
{
  Uint32		i = 0;
  Uint32		*pixels = (Uint32 *)this->_screen->pixels;
  
  while (i < SCREEN_X * SCREEN_Y)
    {
      pixels[i] = 0x00FFFFFF;
      ++i;
    }
  this->updateSurface();
}

void			mySDL2::updateSurface() const
{
  SDL_UpdateWindowSurface(this->_window);  
}

extern "C" IDisplay	*create()
{
  return (new mySDL2());
}
