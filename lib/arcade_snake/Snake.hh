//
// Snake.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:28:09 2016 Erwan Dupard
// Last update Tue Mar 15 17:44:46 2016 Barthelemy Gouby
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <sys/time.h>
# include <iostream>
# include <string>
# include "../../IGame.hh"
# include "SnakePlayer.hh"

# define SNAKE_MAP_WIDTH	30;
# define SNAKE_MAP_HEIGHT	30;
# define SNAKE_TURN_LENGTH	250000;

class			        Snake : public IGame
{
public:
  Snake();
  virtual ~Snake() {  };
  virtual const std::string	&getName() const;
  virtual const std::string	&getInstructions() const;
  virtual void			startGame();
  virtual void			resetGame();
  virtual void		        closeGame();
  void				doTurn();
  virtual void			setLastCommand(const game::Command &command);
  virtual const game::Map	&getMap();
  virtual void			Play();
private:
  std::string			_name;
  std::string			_instructions;
  timeval			_lastTurn;
  game::Map			_map;
  SnakePlayer			_player;
  char				_lastCommand;
};

#endif /* ! SNAKE_HH_ */
