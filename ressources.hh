//
// ressources.hh for arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 15:08:07 2016 Erwan Dupard
// Last update Wed Mar 16 12:43:37 2016 Barthelemy Gouby
//

#ifndef RESSOURCES_HH_
# define RESSOURCES_HH_

# include <iostream>
# include <string>
# include <dlfcn.h>
# include <vector>
# include <utility>
# include "Score.hh"
# include "IDisplay.hh"
# include "IGame.hh"
# include "Loader.hh"

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(1)

# define UNDEFINED_KEY_INPUT		(0x1)

struct					MenuState
{
  const std::vector<std::string>	games;
  const std::vector<std::string>	displays;
  int					index;
};

typedef IGame				*game_create_t();
typedef void				game_destroy_t(IGame *);
typedef IDisplay			*display_create_t();
typedef void				display_destroy_t(IDisplay *);

#endif /* ! RESSOURCES_HH_ */
