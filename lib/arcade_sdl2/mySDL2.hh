//
// mySDL2.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:17:38 2016 Erwan Dupard
// Last update Tue Mar 15 18:39:09 2016 Erwan Dupard
//

#ifndef MYSDL_HH_
# define MYSDL_HH_

# include <iostream>
# include "../../ressources.hh"
# include "../../deps/SDL2/include/SDL.h"
# include "../../IDisplay.hh"

class			        mySDL2 : public IDisplay
{
public:
  mySDL2();
  virtual ~mySDL2() {  };
  virtual const std::string	&getName() const;
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderTitleScreen(const std::string &gameTitle, const std::string &Instructions);
  virtual void			renderMap(const game::Map &map);
  virtual void			renderMenu(MenuState menuState);
  virtual char			getLastInput();
private:
  std::string			_name;
  SDL_Window			*_window;
};

#endif /* ! MYSDL_HH_ */
