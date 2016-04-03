//
// Loader.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:53:55 2016 Erwan Dupard
// Last update Sun Apr  3 21:54:23 2016 Barthelemy Gouby
//

#include "Loader.hh"

Loader::Loader() : _game(0), _display(0), _graphicHandle(0), _gameHandle(0)
{}

Loader::~Loader()
{}

bool				Loader::loadGraphicLibrary(const std::string &filePath)
{
  display_create_t		*create_display;
  void				*oldGraphicHandle = NULL;
  void				*newGraphicHandle = NULL;
  IDisplay			*oldDisplay = NULL;

  if (this->_graphicHandle)
    {
      oldGraphicHandle = this->_graphicHandle;
      oldDisplay = this->_display;
    }
  if ((newGraphicHandle = dlopen(filePath.c_str(), RTLD_LAZY | RTLD_GLOBAL)) == NULL)
    {
      std::cerr << "[-] Failed To Open Library : " << dlerror() << std::endl;
      return (false);
    }
  if ((create_display = (display_create_t *)dlsym(newGraphicHandle, "create")) == NULL)
    {
      dlclose(newGraphicHandle);
      std::cerr << "[-] Failed To Load Symbol : " << dlerror() << std::endl;
      return (false);
    }
  this->_graphicHandle = newGraphicHandle;
  if (oldGraphicHandle)
    {
      oldDisplay->closeDisplay();
      delete oldDisplay;
      dlclose(oldGraphicHandle);
    }
  this->_display = create_display();
  return (true);
}

bool				Loader::loadGameLibrary(const std::string &filePath)
{
  game_create_t			*create_game;

  if (this->_gameHandle)
    {
      this->_display->cleanScreen();
      dlclose(this->_gameHandle);
    }
  if ((this->_gameHandle = dlopen(filePath.c_str(), RTLD_LAZY | RTLD_GLOBAL)) == NULL)
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
      if (*it == filePath)
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

void				Loader::loadInitialGameLibrary(const std::string &filePath)
{
  std::vector<std::string>::iterator it = this->_gamesPaths.begin();

  while (it != this->_gamesPaths.end())
    {
      if (*it == filePath)
	{
	  this->loadGameLibrary(filePath);
	  this->_selectedGame = it;
	  break;
	}
      it++;
    }
  if (it == this->_gamesPaths.end())
    throw std::runtime_error("Library not found");
}

void				Loader::loadNextGraphicLibrary()
{
  if (std::next(this->_selectedDisplay) == this->_displaysPaths.end())
    this->_selectedDisplay = this->_displaysPaths.begin();
  else
    this->_selectedDisplay++;
  if (loadGraphicLibrary(*(this->_selectedDisplay)))
    this->_display->initDisplay();
}

void				Loader::loadNextGameLibrary()
{

  if (std::next(this->_selectedGame) == this->_gamesPaths.end())
    this->_selectedGame = this->_gamesPaths.begin();
  else
    this->_selectedGame++;
  if (loadGameLibrary(*(this->_selectedGame)))
    {
      this->_game->startGame();
    }
}

void				Loader::loadPreviousGraphicLibrary()
{
  if (this->_selectedDisplay == this->_displaysPaths.begin())
    this->_selectedDisplay = std::prev(this->_displaysPaths.end());
  else
    this->_selectedDisplay--;
  if (loadGraphicLibrary(*(this->_selectedDisplay)))
    this->_display->initDisplay();
}

void				Loader::loadPreviousGameLibrary()
{
  if (this->_selectedGame == this->_gamesPaths.begin())
    this->_selectedGame = std::prev(this->_gamesPaths.end());
  else
    this->_selectedGame--;
  if (loadGameLibrary(*this->_selectedGame))
    this->_game->startGame();
}

IGame				*Loader::getGame() const
{
  return (this->_game);
}

IDisplay			*Loader::getDisplay() const
{
  return (this->_display);
}

void				Loader::retrieveFilesNames(std::string directoryPath,
							   std::vector<std::string> &pathsTab)
{
  DIR				*dir;
  dirent			*entry;
  std::regex			isLibrary(".*\\.so");

  if ((dir = opendir(directoryPath.c_str())) == NULL)
    throw std::runtime_error("Failed to open directory");
  while ((entry = readdir(dir)) != NULL)
    {
      if (std::regex_match(entry->d_name, isLibrary))
	pathsTab.push_back(directoryPath + std::string(entry->d_name));
    }
  closedir(dir);
}

void				Loader::loadFilesNames()
{
  retrieveFilesNames("lib/", this->_displaysPaths);
  retrieveFilesNames("games/", this->_gamesPaths);
  for (std::vector<std::string>::iterator it = this->_gamesPaths.begin(); it < this->_gamesPaths.end(); it++)
    std::cout << *it << std::endl;
  for (std::vector<std::string>::iterator it = this->_displaysPaths.begin(); it < this->_displaysPaths.end(); it++)
    std::cout << *it << std::endl;
}

const std::vector<std::string>	&Loader::getGamesPaths() const
{
  return (this->_gamesPaths);
}

const std::vector<std::string>	&Loader::getDisplaysPaths() const
{
  return (this->_displaysPaths);
}
