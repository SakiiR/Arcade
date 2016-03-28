//
// Pacman.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:25:15 2016 Erwan Dupard
// Last update Sat Mar 26 07:25:57 2016 Barthelemy Gouby
//

#ifndef PACMAN_HH_
# define PACMAN_HH_

# include <iostream>
# include "../../IGame.hh"
# include "PacmanRessources.hh"

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
  virtual void			sendLastInput(const char &input);
  virtual const game::Map	&refreshAndGetMap();
  virtual const bool		&getIfGameIsOver() const;
  virtual void			Play();
private:
  std::string			_name;
  std::string			_instructions;
  game::Map			_map;
  bool				_gameIsOver;
  PacmanPlayer		       _player;
};

#endif /* ! PACMAN_HH_ */
