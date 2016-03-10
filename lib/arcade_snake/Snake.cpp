//
// Snake.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:27:46 2016 Erwan Dupard
// Last update Thu Mar 10 14:56:33 2016 Erwan Dupard
//

#include "Snake.hh"

Snake::Snake()
{
  this->_name = "libsnake";
}

const std::string		&Snake::getName() const
{
  return (this->_name);
}

void				Snake::startGame()
{}

void				Snake::closeGame()
{}

void				Snake::executeCommand(const arcade::CommandType &command)
{
  (void)command;
}

const arcade::GetMap		&Snake::getMap()
{
  return (this->_map);
}

void				Snake::display()
{}

void				Snake::Play()
{}

extern "C" Snake		*create()
{
  return (new Snake);
}
