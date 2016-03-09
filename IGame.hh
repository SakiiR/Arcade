//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Wed Mar  9 16:06:19 2016 Erwan Dupard
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include <string>
# include "Protocol.hpp"

class			IGame
{
public:
  virtual const std::string	&getName() const = 0;
  virtual void			startGame() = 0;
  virtual void			closeGame() = 0;
  virtual void			executeCommand(const arcade::CommandType &command) = 0;
  virtual const arcade::GetMap	&getMap() = 0;
  virtual void			display(); // pour la moulinette seulement
};

#endif /* ! IGAME_HH_ */
