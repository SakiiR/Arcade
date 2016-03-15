//
// SnakePlayer.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 12:36:59 2016 Barthelemy Gouby
// Last update Tue Mar 15 14:05:27 2016 Barthelemy Gouby
//

#ifndef _SNAKE_PLAYER_HH_
# define _SNAKE_PLAYER_HH_

# include "Snake.hh"

# define SNAKE_PLAYER_INITIAL_LENGTH = 3;

class		SnakePlayer
{
public:		
  SnakePlayer();
  ~SnakePlayer();
  void		setInitialPosition(); 
  void		movePlayer(arcade::CommandType direction);
  bool		checkIfColision(Position position);
private:
  Position	*_playerBody;
  int		playerLength;
};

#endif /* !_SNAKE_PLAYER_HH_ */
