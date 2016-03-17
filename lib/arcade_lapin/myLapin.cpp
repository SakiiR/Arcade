//
// myLapin.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:59 2016 Erwan Dupard
// Last update Wed Mar 16 20:23:10 2016 Erwan Dupard
//

#include "myLapin.hh"

myLapin::myLapin()
{
  this->_name = "liblapin";
  this->_window = NULL;
}

const std::string	&myLapin::getName() const
{
  return (this->_name);
}

void			myLapin::initDisplay()
{
  this->_window = bunny_start(SCREEN_X, SCREEN_Y, 0, this->_name.c_str());
  
  bunny_display(this->_window);

  bunny_stop(this->_window);
}

void			myLapin::closeDisplay()
{}

void			myLapin::renderTitleScreen(const std::string &gameTitle, const std::string &instructions)
{
  (void)gameTitle;
  (void)instructions;
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

extern "C" IDisplay	*create()
{
  return (new myLapin);
}
