//
// PacmanRessources.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Fri Mar 18 17:01:04 2016 Barthelemy Gouby
// Last update Thu Mar 31 15:59:59 2016 Barthelemy Gouby
//

#ifndef _PACMAN_RESSOURCES_
# define _PACMAN_RESSOURCES_

# include <sys/time.h>
# include "../../IGame.hh"

# define PACMAN_MAP_WIDTH	(31)
# define PACMAN_MAP_HEIGHT	(23)
# define PACMAN_TURN_LENGTH	(100000)
# define PACMAN_POWERUP_LENGTH	(30 * PACMAN_TURN_LENGTH)
# define GHOST_DEATH_DURATION	(30 * PACMAN_TURN_LENGTH)

extern int pacmanMap[961];

#endif /* !PACMAN_RESSOURCES */
