//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Tue Mar  8 17:06:38 2016 Barthelemy Gouby
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
  virtual void			executeCommand(const CommandType &command) = 0;
  virtual GetMap&		getMap() = 0;
  virtual void			display(); // pour la moulinette seulement
  // etc etc
};

#endif /* ! IGAME_HH_ */
