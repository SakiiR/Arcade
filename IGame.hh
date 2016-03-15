//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Tue Mar 15 17:43:50 2016 Erwan Dupard
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include <string>
# include "Protocol.hpp"

namespace			game
{
  enum				Command
    {
      GO_UP,
      GO_DOWN,
      GO_LEFT,
      GO_RIGHT,
      GO_FORWARD,
      SHOOT,
      PLAY
    };
  
  enum				Tile
    {
      EMPTY,	
      BLOCK,
      OBSTACLE,
      EVIL_DUDE,
      GHOST,
      EVIL_SHOOT,
      MY_SHOOT,
      POWERUP,
      PLAYER,
      SNAKE,
      PACMAN
    };
  
  struct			Position
  {
    int				x;
    int				y;
  };

  struct			Map
  {
    int				width;
    int				heigth;
    Tile			*tiles;
  };
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
  virtual const game::Map	&getMap() = 0;
};

#endif /* ! IGAME_HH_ */
