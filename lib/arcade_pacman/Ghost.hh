//
// Ghost.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon Mar 28 16:53:01 2016 Barthelemy Gouby
// Last update Tue Mar 29 17:40:58 2016 Barthelemy Gouby
//

#ifndef _GHOST_HH_
# define _GHOST_HH_

# include <random>
# include <vector>
# include "PacmanRessources.hh"

class				Ghost
{
public:
  Ghost(const game::Position initialPosition, const game::Direction initialDirection, game::Map &map);
  ~Ghost();
  void				moveGhost(game::Map &map, bool &gameIsOver, bool &hunter);
  bool				getIfDead();

private:
  game::Position		_ghostPosition;
  game::Direction		_movementDirection;
  bool				_isDead;
  game::Tile			_savedTile;

  game::Position		findNextPosition(const game::Direction &direction) const;
  std::vector<game::Direction>	getPossibleDirections(const game::Map &map) const;
};

#endif /* ! _GHOST_HH_ */
