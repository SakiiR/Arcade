//
// mySDL2.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:16:43 2016 Erwan Dupard
// Last update Thu Mar 10 13:11:56 2016 Erwan Dupard
//

#include "mySDL2.hh"

mySDL2::mySDL2()
{
  this->_name = "libsdl2";
}

const std::string	&mySDL2::getName() const
{
  return (this->_name);
}

void			mySDL2::initDisplay()
{}

void			mySDL2::closeDisplay()
{}

void			mySDL2::renderMap(const arcade::GetMap &map)
{
  (void)map;
}

void			mySDL2::renderMenu(MenuState menuState)
{
  (void)menuState;
}

char			mySDL2::getLastInput()
{
  return ('\\');
}

extern "C" mySDL2	*create() {
  return (new mySDL2);
}
