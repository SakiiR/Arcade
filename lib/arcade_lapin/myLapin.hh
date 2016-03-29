//
// myLapin.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:51 2016 Erwan Dupard
// Last update Fri Mar 25 17:51:21 2016 Erwan Dupard
//

#ifndef MYLAPIN_HH_
# define MYLAPIN_HH_

# include <iostream>
# include "lapin.h"
# include "../../IDisplay.hh"

# define SCREEN_X		(600)
# define SCREEN_Y		(600)

# define SNAKE_COLOR		(BLUE)
# define OBSTACLE_COLOR		(BLACK)
# define POWERUP_COLOR		(GREEN)
# define VOID_COLOR		(WHITE)

class			        myLapin : public IDisplay
{
public:
  myLapin();
  virtual ~myLapin() {  };
  virtual const std::string	&getName() const;
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderTitleScreen(const std::string &gameTitle, const std::string &instructions);
  virtual void			renderMap(const game::Map &map);
  virtual void			renderMenu(MenuState menuState);
  virtual char			getLastInput();
private:
  std::string			_name;
  t_bunny_window		*_window;
  t_bunny_pixelarray		*_screen;
  void				_updateWindow();
  void				_writeTile(const game::Position &position, const game::Position &size, unsigned int color);
};

# endif /* ! MYLAPIN_HH_ */
