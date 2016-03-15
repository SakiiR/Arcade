//
// SnakePlayer.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 12:36:59 2016 Barthelemy Gouby
// Last update Tue Mar 15 17:44:56 2016 Barthelemy Gouby
//

#ifndef _SNAKE_PLAYER_HH_
# define _SNAKE_PLAYER_HH_

# include "Snake.hh"

# define SNAKE_PLAYER_INITIAL_LENGTH	3;

class			SnakePlayer
{

public:		
  SnakePlayer();
  ~SnakePlayer();
  void			setInitialPosition(); 
  void			setMovementDirection(game::Direction direction);
  void			movePlayer();
  void			incrementSize();
  bool			checkIfColision(game::Position position);
private:
  game::Position	*_playerBody;
  int			_playerLength;
  game::Direction	_movementDirection;
};

#endif /* !_SNAKE_PLAYER_HH_ */
