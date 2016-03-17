//
// Loader.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:53:55 2016 Erwan Dupard
// Last update Wed Mar 16 22:49:04 2016 Erwan Dupard
//

#include "Loader.hh"

Loader::Loader() : _game(0), _display(0)
{
  std::cout << "[^] Loader initialisation .." << std::endl;
}

Loader::~Loader()
{
  std::cout << "[^] Loader destruction .." << std::endl;
}

bool				Loader::loadGraphicLibrary(const std::string &filePath)
{
  void				*handle;
  display_create_t		*create_display;

  std::cout << "[^] Loading Graphic Library.." << std::endl;
  if ((handle = dlopen(filePath.c_str(), RTLD_NOW)) == NULL)
    {
      std::cerr << "[-] Failed To Open Library : " << dlerror() << std::endl;
      return (false);
    }
  if ((create_display = (display_create_t *)dlsym(handle, "create")) == NULL)
    {
      std::cerr << "[-] Failed To Load Symbol : " << dlerror() << std::endl;
      return (false);
    }
  this->_display = create_display();
  std::cout << "[+] Graphic library loaded : " << this->_display << " !" << std::endl;
  return (true);
}

bool				Loader::loadGameLibrary(const std::string &filePath)
{
  void				*handle;
  game_create_t			*create_game;

  std::cout << "[^] Loading Game Library.." << std::endl;
  if ((handle = dlopen(filePath.c_str(), RTLD_NOW)) == NULL)
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
  std::cout << "[+] Game library loaded : " << this->_game << " !" << std::endl;
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
