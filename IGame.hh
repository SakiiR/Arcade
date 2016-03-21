//
// IGame.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:37:14 2016 Erwan Dupard
// Last update Fri Mar 18 17:39:49 2016 Barthelemy Gouby
//

#ifndef IGAME_HH_
# define IGAME_HH_

# include <stdexcept>
# include <exception>
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
      SHOOT
    };
  
  enum				Direction
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };
  
  enum				Tile : int
    {
      EMPTY = 0,	
      BLOCK = 1,
      OBSTACLE = 2,
      EVIL_DUDE = 3,
      GHOST = 4,
      EVIL_SHOOT = 5,
      MY_SHOOT = 6,
      POWERUP = 7,
      PLAYER = 8,
      SNAKE = 9,
      PACMAN = 10
    };

  struct			Position
  {
    Position() {};
    Position(unsigned int X, unsigned int Y) : x(X), y(Y) {  };
    unsigned int		x;
    unsigned int		y;
  };  
  
  class				Map
  {
  public:
    Map(unsigned int width, unsigned int height);
    Map(unsigned int width, unsigned int height, int *tiles);
    ~Map();
    void			changeTile(const Position &position, const Tile &type);
    const unsigned int		&getWidth() const;
    const unsigned int		&getHeight() const;
    game::Tile			*getTiles() const;
    const game::Tile		&getTileAt(const game::Position position) const;
  private:
    unsigned int		_width;
    unsigned int		_height;
    game::Tile			*_tiles;
  };
}

class				IGame
{
public:
  virtual ~IGame() { };
  virtual const std::string	&getName() const = 0;
  virtual const std::string	&getInstructions() const = 0;
  virtual void			startGame() = 0;
  virtual void			resetGame() = 0;
  virtual void			closeGame() = 0;
  virtual void			sendLastInput(const char &input) = 0;
  virtual const game::Map	&refreshAndGetMap() = 0;
  virtual const bool		&getIfGameIsOver() const = 0;
  virtual void			Play() = 0;
};

#endif /* ! IGAME_HH_ */
