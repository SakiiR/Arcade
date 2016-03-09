//
// Loader.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 15:36:22 2016 Erwan Dupard
// Last update Wed Mar  9 16:04:56 2016 Erwan Dupard
//

#ifndef LOADER_HH_
# define LOADER_HH_

# include "ressources.hh"

class			Loader
{
public:
  Loader();
  ~Loader();
  bool			loadGraphicLibrary(const char *);
  bool			loadGameLibrary(const char *);
private:
  IGame			*_game;
  IDisplay		*_gLibrary;
};

#endif /* ! LOADER_HH_ */
