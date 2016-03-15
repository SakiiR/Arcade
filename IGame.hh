//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Tue Mar 15 14:25:09 2016 Barthelemy Gouby
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include <string>
# include "Protocol.hpp"

struct				Map
{
  int				width;
  int				heigth;
  arcade::TileType		*tiles;
}

class				IGame
{
public:
  virtual const std::string	&getName() const = 0;
  virtual const std::string	&getInstructions() const = 0;
  virtual void			startGame() = 0;
  virtual void			resetGame() = 0;
  virtual void			closeGame() = 0;
  virtual void			sendLastInput(const char &input) = 0;
  virtual const Map		&getMap() = 0;
};

#endif /* ! IGAME_HH_ */
