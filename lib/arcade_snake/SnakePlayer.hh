//
// SnakePlayer.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 12:36:59 2016 Barthelemy Gouby
// Last update Wed Mar 30 13:37:33 2016 Barthelemy Gouby
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
  const size_t		&getLength() const;
  const game::Position	*getBody() const;
private:
  game::Position	*_playerBody;
  size_t		_playerLength;
  game::Direction	_movementDirection;
};

#endif /* !_SNAKE_PLAYER_HH_ */
