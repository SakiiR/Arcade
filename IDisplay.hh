//
// IDisplay.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:36:09 2016 Erwan Dupard
// Last update Wed Mar  9 17:07:32 2016 Erwan Dupard
//

#ifndef IDISPLAY_HH_
# define IDISPLAY_HH_

# include <string>
# include "Protocol.hpp"
# include "ressources.hh"

struct				MenuState;

class				IDisplay
{
public:
  virtual const std::string	&getName() const = 0;
  virtual void			initDisplay() = 0;
  virtual void			closeDisplay() = 0;
  virtual void			renderMap(const arcade::GetMap &map) = 0;
  virtual void			renderMenu(MenuState menuState) = 0;
};

#endif /* ! IDISPLAY_HH_ */
