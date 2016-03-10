//
// Pacman.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:24:59 2016 Erwan Dupard
// Last update Thu Mar 10 15:03:59 2016 Erwan Dupard
//

#include "Pacman.hh"

Pacman::Pacman()
{
  this->_name = "libsnake";
}

const std::string		&Pacman::getName() const
{
  return (this->_name);
}

void				Pacman::startGame()
{}

void				Pacman::closeGame()
{}

void				Pacman::executeCommand(const arcade::CommandType &command)
{
  (void)command;
}

const arcade::GetMap		&Pacman::getMap()
{
  return (this->_map);
}

void				Pacman::display()
{}

void				Pacman::Play()
{}

extern "C" Pacman		*create()
{
  return (new Pacman);
}
