//
// myLapin.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:51 2016 Erwan Dupard
// Last update Thu Mar 10 15:04:30 2016 Erwan Dupard
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
  virtual void			renderMap(const arcade::GetMap &map);
  virtual void			renderMenu(MenuState menuState);
  virtual char			getLastInput();
private:
  std::string			_name;
};

# endif /* ! MYLAPIN_HH_ */
