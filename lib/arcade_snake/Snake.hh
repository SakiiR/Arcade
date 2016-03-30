//
// Snake.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:28:09 2016 Erwan Dupard
// Last update Wed Mar 30 16:28:30 2016 Barthelemy Gouby
//

#ifndef SNAKE_HH_
# define SNAKE_HH_

# include <random>
# include <sys/time.h>
# include <iostream>
# include <string>
# include "../../IGame.hh"
# include "SnakePlayer.hh"
# include "SnakeRessources.hh"
# include "../../Protocol.hpp"

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
  void				createPowerUp();
  virtual void			sendLastInput(const char &input);
  virtual const game::Map	&refreshAndGetMap();
  virtual const bool		&getIfGameIsOver() const;
  // // virtual void			Play();
  void				getMap();
  void				whereAmI();
private:
  std::string			_name;
  std::string			_instructions;
  timeval			_lastTurn;
  game::Map			_map;
  SnakePlayer			_player;
  char				_lastCommand;
  bool				_gameIsOver;
  game::Position		_powerUp;
};

struct		GetMap
  {
    arcade::CommandType		type;
    uint16_t			width;
    uint16_t			height;
    arcade::TileType		tile[SNAKE_MAP_WIDTH * SNAKE_MAP_HEIGHT];
} __attribute__((packed));

struct		WhereAmI
{
  arcade::CommandType		type;
  uint16_t			length;
  arcade::Position		position[SNAKE_MAP_WIDTH * SNAKE_MAP_HEIGHT];
} __attribute__((packed));


#endif /* ! SNAKE_HH_ */
