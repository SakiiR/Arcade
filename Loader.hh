//
// Loader.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:36:22 2016 Erwan Dupard
// Last update Thu Mar 10 17:40:38 2016 Erwan Dupard
//

#ifndef LOADER_HH_
# define LOADER_HH_

# include "ressources.hh"

class			IDisplay;

class			Loader
{
public:
  Loader();
  ~Loader();
  bool			loadGraphicLibrary(const char *);
  bool			loadGameLibrary(const char *);
  IGame			*getGame() const;
  IDisplay		*getDisplay() const;
private:
  IGame			*_game;
  IDisplay		*_display;
};

#endif /* ! LOADER_HH_ */
