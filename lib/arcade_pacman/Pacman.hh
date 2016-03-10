//
// Pacman.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:25:15 2016 Erwan Dupard
// Last update Thu Mar 10 15:03:28 2016 Erwan Dupard
//

#ifndef PACMAN_HH_
# define PACMAN_HH_

# include <iostream>
# include "../../IGame.hh"

class			        Pacman : public IGame
{
public:
  Pacman();
  virtual ~Pacman() {  };
  virtual const std::string	&getName() const;
  virtual void			startGame();
  virtual void		        closeGame();
  virtual void			executeCommand(const arcade::CommandType &command);
  virtual const arcade::GetMap	&getMap();
  virtual void			display();
  virtual void			Play();
private:
  std::string			_name;
  arcade::GetMap		_map;
};

#endif /* ! PACMAN_HH_ */
