//
// myCaca.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:20:17 2016 Erwan Dupard
// Last update Thu Mar 10 16:18:16 2016 Erwan Dupard
//

#include "myCaca.hh"

myCaca::myCaca()
{
  this->_name = "libcaca";
}

const std::string	&myCaca::getName() const
{
  return (this->_name);
}

void		myCaca::initDisplay()
{

}

void		myCaca::closeDisplay()
{}

void		myCaca::renderMap(const arcade::GetMap &map)
{
  (void)map;
}

void		myCaca::renderMenu(MenuState menuState)
{
  (void)menuState;
}

char		myCaca::getLastInput()
{
  return ('\\');
}

extern "C" myCaca	*create()
{
  return (new myCaca);
}
