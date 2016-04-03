//
// caca.hh for arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 17:55:00 2016 Erwan Dupard
// Last update Sat Apr  2 12:21:16 2016 Erwan Dupard
//

#ifndef MYCACA_HH_
# define MYCACA_HH_

# include <iostream>
# include "caca.h"
# include "../../IDisplay.hh"

class				myCaca : public IDisplay
{
public:
  myCaca();
  virtual ~myCaca() {  };
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderTitleScreen(const std::string &gameTitle, const std::string &instructions);
  virtual void			renderMap(const game::Map &map, char c);
  virtual void			renderMenu(const MenuState &menuState);
  virtual char			getLastInput();
  virtual void			cleanScreen();
private:
  std::string			_name;
  caca_canvas_t			*_canvas;
  caca_display_t		*_display;
  caca_event_t			_event;
  void				_drawShit();
};

#endif /* ! MYCACA_HH_ */
