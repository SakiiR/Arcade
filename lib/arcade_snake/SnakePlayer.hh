//
// SnakePlayer.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 12:36:59 2016 Barthelemy Gouby
// Last update Thu Mar 17 15:39:07 2016 Barthelemy Gouby
//

#ifndef _SNAKE_PLAYER_HH_
# define _SNAKE_PLAYER_HH_

# include "../../IGame.hh"
# include "SnakeRessources.hh"

class			SnakePlayer
{

public:		
  SnakePlayer();
  ~SnakePlayer();
  void			setInitialPosition(game::Map &map); 
  void			setMovementDirection(game::Direction direction);
  bool			movePlayer(game::Map &map);
  void			incrementSize();
private:
  game::Position	*_playerBody;
  int			_playerLength;
  game::Direction	_movementDirection;
};

#endif /* !_SNAKE_PLAYER_HH_ */
