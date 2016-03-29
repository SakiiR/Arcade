//
// Ghost.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon Mar 28 16:53:01 2016 Barthelemy Gouby
// Last update Mon Mar 28 18:01:18 2016 Barthelemy Gouby
//

#ifndef _GHOST_HH_
# define _GHOST_HH_

# include "PacmanRessources.hh"

class			Ghost
{
public:
  Ghost();
  ~Ghost();
  void			moveGhost();
private:
  game::Position	_ghostPosition;
  game::Direction	_movementDirection;
};

#endif _GHOST_HH_
