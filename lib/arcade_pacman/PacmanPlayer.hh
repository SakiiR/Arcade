//
// PacmanPlayer.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Sat Mar 26 07:26:07 2016 Barthelemy Gouby
// Last update Tue Mar 29 16:33:51 2016 Barthelemy Gouby
//

#ifndef _PACMAN_PLAYER_
# define _PACMAN_PLAYER_

# include "../../IGame.hh"
# include "PacmanRessources.hh"

class			PacmanPlayer
{
public:
  PacmanPlayer();
  ~PacmanPlayer();
  void			setMovementDirection(const game::Direction &direction, const game::Map &map);
  void			movePlayer(game::Map &map, bool &gameIsOver);
private:
  game::Position	_playerPosition;
  game::Direction	_movementDirection;

  game::Position	findNextPosition(const game::Direction &direction);

};

#endif /* ! _PACMAN_PLAYER_ */
