//
// Loader.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:53:55 2016 Erwan Dupard
// Last update Thu Mar 31 15:45:12 2016 Erwan Dupard
//

#include "Loader.hh"

Loader::Loader() : _game(0), _display(0), _graphicHandle(0), _gameHandle(0)
{}

Loader::~Loader()
{}

bool				Loader::loadGraphicLibrary(const std::string &filePath)
{
  display_create_t		*create_display;

  if (this->_graphicHandle)
    dlclose(this->_graphicHandle);
  if ((this->_graphicHandle = dlopen(filePath.c_str(), RTLD_NOW)) == NULL)
    {
      std::cerr << "[-] Failed To Open Library : " << dlerror() << std::endl;
      return (false);
    }
  if ((create_display = (display_create_t *)dlsym(this->_graphicHandle, "create")) == NULL)
    {
      std::cerr << "[-] Failed To Load Symbol : " << dlerror() << std::endl;
      return (false);
    }
  this->_display = create_display();
  return (true);
}

bool				Loader::loadGameLibrary(const std::string &filePath)
{
  game_create_t			*create_game;

  if (this->_gameHandle)
    dlclose(this->_gameHandle);
  if ((this->_gameHandle = dlopen(filePath.c_str(), RTLD_NOW)) == NULL)
    {
      std::cerr << "[-] Failed To Open Library : " << dlerror() << std::endl;
      return (false);
    }
  if ((create_game = (game_create_t *)dlsym(this->_gameHandle, "create")) == NULL)
    {
      std::cerr << "[-] Failed To Load Symbol : " << dlerror() << std::endl;
      return (false);
    }
  this->_game = create_game();
  return (true);
}

void				Loader::loadInitialGraphicLibrary(const std::string &filePath)
{
  std::vector<std::string>::iterator it = this->_displaysPaths.begin();

  while (it != this->_displaysPaths.end())
    {
      if (("./lib/" + *it) == filePath)
	{
	  this->loadGraphicLibrary(filePath);
	  this->_selectedDisplay = it;
	  break;
	}
      it++;
    }
  if (it == this->_displaysPaths.end())
    throw std::runtime_error("Library not found");
}

void				Loader::loadNextGraphicLibrary()
{
  if (std::next(this->_selectedDisplay) == this->_displaysPaths.end())
    this->_selectedDisplay = this->_displaysPaths.begin();
  else
    this->_selectedDisplay++;
  loadGraphicLibrary(*this->_selectedDisplay);
}

void				Loader::loadNextGameLibrary()
{
  if (std::next(this->_selectedGame) == this->_gamesPaths.end())
    this->_selectedGame = this->_gamesPaths.begin();
  else
    this->_selectedGame++;
  loadGameLibrary(*this->_selectedGame);
}

void				Loader::loadPreviousGraphicLibrary()
{
  if (this->_selectedDisplay == this->_displaysPaths.begin())
    this->_selectedDisplay = std::prev(this->_displaysPaths.end());
  else
    this->_selectedDisplay--;
  loadGraphicLibrary(*(this->_selectedDisplay));
}

void				Loader::loadPreviousGameLibrary()
{
  if (this->_selectedGame == this->_gamesPaths.begin())
    this->_selectedGame = std::prev(this->_gamesPaths.end());
  else
    this->_selectedGame--;
  loadGameLibrary(*this->_selectedGame);
}

IGame				*Loader::getGame() const
{
  return (this->_game);
}

IDisplay			*Loader::getDisplay() const
{
  return (this->_display);
}

void				Loader::retrieveFilesNames(char *directoryPath, std::vector<std::string> pathsTab)
{
  DIR				*dir;
  dirent			*entry;

  if ((dir = opendir(directoryPath)) == NULL)
    throw std::runtime_error("Failed to open directory");
  while ((entry = readdir(dir)) != NULL)
    pathsTab.push_back(std::string(entry->d_name));
  closedir(dir);
}
