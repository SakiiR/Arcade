//
// IDisplay.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:36:09 2016 Erwan Dupard
// Last update Fri Apr  1 18:07:03 2016 Erwan Dupard
//

#ifndef IDISPLAY_HH_
# define IDISPLAY_HH_

# include <exception>
# include <stdexcept>
# include <string>
# include "IGame.hh"
# include "ressources.hh"

struct				MenuState;

class				IDisplay
{
public:
  virtual ~IDisplay() {  };
  virtual void			initDisplay() = 0;
  virtual void			closeDisplay() = 0;
  virtual void			renderMap(const game::Map &map, char) = 0;
  virtual void			renderMenu(const MenuState &menuState) = 0;
  virtual char			getLastInput() = 0;
  virtual void			cleanScreen() = 0;
};

#endif /* ! IDISPLAY_HH_ */
