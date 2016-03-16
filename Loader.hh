//
// Loader.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:36:22 2016 Erwan Dupard
// Last update Wed Mar 16 22:48:35 2016 Erwan Dupard
//

#ifndef LOADER_HH_
# define LOADER_HH_

# include <dirent.h>
# include "ressources.hh"

class					IDisplay;

class					Loader
{
public:
  Loader();
  ~Loader();
  bool					loadGraphicLibrary(const std::string &filePath);
  bool					loadGameLibrary(const std::string &filePath);
  void					loadInitialGraphicLibrary(const std::string &filePath);
  // void				loadInitialGameLibrary(const std::string filePath); peut etre pas besoin
  void					loadNextGraphicLibrary();
  void					loadNextGameLibrary();
  void					loadPreviousGraphicLibrary();
  void					loadPreviousGameLibrary();
  IGame					*getGame() const;
  IDisplay				*getDisplay() const;
  void					retrieveFilesNames(char *directoryPath, std::vector<std::string> pathsTab);
private:
  IGame					*_game;
  std::vector<std::string>		_gamesPaths;
  std::vector<std::string>::iterator	_selectedGame;
  IDisplay				*_display;
  std::vector<std::string>		_displaysPaths;
  std::vector<std::string>::iterator	_selectedDisplay;
};

#endif /* ! LOADER_HH_ */
