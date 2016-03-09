//
// Loader.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:53:55 2016 Erwan Dupard
// Last update Wed Mar  9 16:30:28 2016 Erwan Dupard
//

#include "Loader.hh"

Loader::Loader() : _game(0), _gLibrary(0)
{
  std::cout << "[^] Loader initialisation .." << std::endl;
}

Loader::~Loader()
{}

bool				Loader::loadGraphicLibrary(const char *fileName)
{
  void				*handle;
  display_create_t		*create_display;

  std::cout << "[^] Loading Graphic Library.." << std::endl;
  if ((handle = dlopen(fileName, RTLD_NOW)) == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (false);
    }
  if ((create_display = (display_create_t *)dlsym(handle, "create")) == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (false);
    }
  this->_gLibrary = create_display();
  return (true);
}

bool				Loader::loadGameLibrary(const char *fileName)
{

  void				*handle;
  game_create_t			*create_game;

  std::cout << "[^] Loading Game Library.." << std::endl;
  if ((handle = dlopen(fileName, RTLD_NOW)) == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (false);
    }
  if ((create_game = (game_create_t *)dlsym(handle, "create")) == NULL)
    {
      std::cerr << dlerror() << std::endl;
      return (false);
    }
  this->_game = create_game();
  return (true);
}
