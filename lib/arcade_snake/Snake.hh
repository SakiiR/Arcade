//
// Snake.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:28:09 2016 Erwan Dupard
// Last update Fri Mar 11 10:19:44 2016 Erwan Dupard
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <iostream>
# include "../../IGame.hh"

class			        Snake : public IGame
{
public:
  Snake();
  virtual ~Snake() {  };
  virtual const std::string	&getName() const;
  virtual void			startGame();
  virtual void		        closeGame();
  virtual void			setLastCommand(const arcade::CommandType &command);
  virtual const arcade::GetMap	&getMap();
  virtual void			display();
  virtual void			Play();
private:
  std::string			_name;
  arcade::GetMap		_map;
};

#endif /* ! SNAKE_HH_ */
