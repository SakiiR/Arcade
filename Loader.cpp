//
// Loader.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:53:55 2016 Erwan Dupard
// Last update Wed Mar  9 16:50:44 2016 Erwan Dupard
//

#include "Loader.hh"

Loader::Loader() : _game(0), _gLibrary(0)
{
  std::cout << "[^] Loader initialisation .." << std::endl;
}

Loader::~Loader()
{
  std::cout << "[^] Loader destruction .." << std::endl;
}

bool				Loader::loadGraphicLibrary(const char *fileName)
{
  void				*handle;
  display_create_t		*create_display;

  std::cout << "[^] Loading Graphic Library.." << std::endl;
  if ((handle = dlopen(fileName, RTLD_NOW)) == NULL)
    {
      std::cerr << "[-] Failed To Open Library : " << dlerror() << std::endl;
      return (false);
    }
  if ((create_display = (display_create_t *)dlsym(handle, "create")) == NULL)
    {
      std::cerr << "[-] Failed To Load Symbol : " << dlerror() << std::endl;
      return (false);
    }
  this->_gLibrary = create_display();
  dlclose(handle);
  return (true);
}

bool				Loader::loadGameLibrary(const char *fileName)
{
  void				*handle;
  game_create_t			*create_game;

  std::cout << "[^] Loading Game Library.." << std::endl;
  if ((handle = dlopen(fileName, RTLD_NOW)) == NULL)
    {
      std::cerr << "[-] Failed To Open Library : " << dlerror() << std::endl;
      return (false);
    }
  if ((create_game = (game_create_t *)dlsym(handle, "create")) == NULL)
    {
      std::cerr << "[-] Failed To Load Symbol : " << dlerror() << std::endl;
      return (false);
    }
  this->_game = create_game();
  dlclose(handle);
  return (true);
}

IGame				*Loader::getGame() const
{
  return (this->_game);
}

IDisplay			*Loader::getDisplay() const
{
  return (this->_gLibrary);
}
