//
// Pacman.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:25:15 2016 Erwan Dupard
// Last update Thu Mar 31 16:01:25 2016 Barthelemy Gouby
//

#ifndef PACMAN_HH_
# define PACMAN_HH_

# include <vector>
# include <iostream>
# include "../../IGame.hh"
# include "PacmanRessources.hh"
# include "PacmanPlayer.hh"
# include "Ghost.hh"

class			        Pacman : public IGame
{
public:
  Pacman();
  virtual ~Pacman() {  };
  virtual const std::string	&getName() const;
  virtual const std::string	&getInstructions() const;
  virtual void			startGame();
  virtual void			resetGame();
  virtual void			closeGame();
  void				doTurn();
  virtual void			sendLastInput(const char &input);
  virtual const game::Map	&refreshAndGetMap();
  virtual const bool		&getIfGameIsOver() const;
  void				testIfVictory();
  void				whereAmI();
  void				getMap();

private:
  std::string			_name;
  std::string			_instructions;
  timeval			_lastTurn;
  timeval			_powerBeginTime;
  game::Map			_map;
  PacmanPlayer			_player;
  game::Direction		_lastCommand;
  bool				_gameIsOver;
  bool				_victory;
  std::vector<Ghost>		_ghosts;
  bool				_pacmanHunted;
};

struct		GetMap
  {
    arcade::CommandType		type;
    uint16_t			width;
    uint16_t			height;
    arcade::TileType		tile[PACMAN_MAP_WIDTH * PACMAN_MAP_HEIGHT];
} __attribute__((packed));

struct		WhereAmI
{
  arcade::CommandType		type;
  uint16_t			length;
  arcade::Position		position[1];
} __attribute__((packed));


#endif /* ! PACMAN_HH_ */
