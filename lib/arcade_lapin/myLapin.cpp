//
// myLapin.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:59 2016 Erwan Dupard
// Last update Tue Mar 15 19:48:55 2016 Erwan Dupard
//

#include "myLapin.hh"

myLapin::myLapin()
{
  this->_name = "liblapin";
}

const std::string	&myLapin::getName() const
{
  return (this->_name);
}

void			myLapin::initDisplay()
{}

void			myLapin::closeDisplay()
{}

void			myLapin::renderTitleScreen(const std::string &gameTitle, const std::string &instructions)
{
  (void)gameTitle;
  (void)Instructions;
}

void			myLapin::renderMap(const game::Map &map)
{
  (void)map;
}

void			myLapin::renderMenu(MenuState menuState)
{
  (void)menuState;
}

char			myLapin::getLastInput()
{
  return ('\\');
}

extern "C" myLapin	*create()
{
  return (new myLapin);
}
