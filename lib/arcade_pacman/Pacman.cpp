//
// Pacman.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:24:59 2016 Erwan Dupard
// Last update Fri Mar 18 17:53:42 2016 Barthelemy Gouby
//

#include "Pacman.hh"

Pacman::Pacman()
  : _map(PACMAN_MAP_WIDTH, PACMAN_MAP_HEIGHT, pacmanMap)
{
  this->_name = "libsnake";
  this->_gameIsOver = false;
}

const std::string		&Pacman::getName() const
{
  return (this->_name);
}

const std::string		&Pacman::getInstructions() const
{
  return (this->_instructions);
}

void				Pacman::startGame()
{}

void				Pacman::resetGame()
{

}

void				Pacman::closeGame()
{}

void				Pacman::sendLastInput(const char &input)
{
  (void)input;
}

const game::Map			&Pacman::refreshAndGetMap()
{
  return (this->_map);
}

const bool			&Pacman::getIfGameIsOver() const
{
  return (this->_gameIsOver);
}

void				Pacman::Play()
{}

extern "C" Pacman		*create()
{
  return (new Pacman);
}
