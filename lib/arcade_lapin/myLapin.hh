//
// myLapin.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:51 2016 Erwan Dupard
// Last update Tue Mar 15 19:49:01 2016 Erwan Dupard
//

#ifndef MYLAPIN_HH_
# define MYLAPIN_HH_

# include <iostream>
# include "../../deps/lapin/include/lapin.h"
# include "../../IDisplay.hh"

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
};

# endif /* ! MYLAPIN_HH_ */
