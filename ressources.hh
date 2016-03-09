//
// ressources.hh for arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 15:08:07 2016 Erwan Dupard
// Last update Wed Mar  9 16:38:08 2016 Erwan Dupard
//

#ifndef RESSOURCES_HH_
# define RESSOURCES_HH_

# include <iostream>
# include <string>
# include <dlfcn.h>
# include "Score.hh"
# include "IDisplay.hh"
# include "IGame.hh"
# include "Loader.hh"

# define RETURN_SUCCESS		(0)
# define RETURN_FAILURE		(1)

typedef IGame			*game_create_t();
typedef void			game_destroy_t(IGame *);
typedef IDisplay		*display_create_t();
typedef void			display_destroy_t(IDisplay *);

#endif /* ! RESSOURCES_HH_ */
