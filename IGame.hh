//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Thu Mar 10 16:51:32 2016 Barthelemy Gouby
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include <string>
# include "Protocol.hpp"

class				IGame
{
public:
  virtual const std::string	&getName() const = 0;
  virtual void			startGame() = 0;
  virtual void			closeGame() = 0;
  virtual void			setLastCommand(const arcade::CommandType &command) = 0;
  virtual const arcade::GetMap	&getMap() = 0;
  virtual void			display(); // pour la moulinette seulement
  virtual void			Play(void) = 0;
};

#endif /* ! IGAME_HH_ */
