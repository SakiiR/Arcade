//
// Snake.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:28:09 2016 Erwan Dupard
// Last update Thu Mar 17 12:29:43 2016 Barthelemy Gouby
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <sys/time.h>
# include <iostream>
# include <string>
# include "../../IGame.hh"
# include "SnakePlayer.hh"
# include "SnakeRessources.hh"

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
  virtual void			sendLastInput(const char &input);
  virtual const game::Map	&getMap();
  virtual const bool		&getIfGameIsOver() const;
  virtual void			Play();
private:
  std::string			_name;
  std::string			_instructions;
  timeval			_lastTurn;
  game::Map			_map;
  SnakePlayer			_player;
  char				_lastCommand;
  bool				_gameIsOver;
};

#endif /* ! SNAKE_HH_ */
