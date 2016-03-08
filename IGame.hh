//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Tue Mar  8 16:47:42 2016 Barthelemy Gouby
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include <string>

class			IGame
{
public:
  virtual std::string const	getName() const = 0;
  virtual void			startGame() = 0;
  virtual void			closeGame() = 0;
  virtual void			sendCommand(CommandType command) = 0;
  // etc etc
};

#endif /* ! IGAME_HH_ */
