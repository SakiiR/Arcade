//
// mySDL2.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:16:43 2016 Erwan Dupard
// Last update Thu Mar 10 17:46:14 2016 Erwan Dupard
//

#include "mySDL2.hh"

mySDL2::mySDL2()
{
  this->_name = "libsdl2";
  this->_window = NULL;
  std::cout << "[^] mySDL2 constructor !" << std::endl;
}

const std::string	&mySDL2::getName() const
{
  return (this->_name);
}

void			mySDL2::initDisplay()
{
  SDL_Surface* screenSurface = NULL;
  
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  else
    {
      this->_window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
      if(this->_window == NULL )
  	printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
      else
  	{
  	  screenSurface = SDL_GetWindowSurface(this->_window);
  	  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
  	  SDL_UpdateWindowSurface(this->_window);
  	  SDL_Delay(2000);
  	}
    }
}

void			mySDL2::closeDisplay()
{
  SDL_DestroyWindow(this->_window);
  SDL_Quit();
}

void			mySDL2::renderMap(const arcade::GetMap &map)
{
  (void)map;
}

void			mySDL2::renderMenu(MenuState menuState)
{
  (void)menuState;
}

char			mySDL2::getLastInput()
{
  return ('\\');
}

extern "C" IDisplay	*create()
{
  return (new mySDL2());
}
