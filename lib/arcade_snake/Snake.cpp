//
// Snake.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:27:46 2016 Erwan Dupard
// Last update Tue Mar 15 14:49:17 2016 Barthelemy Gouby
//

#include "Snake.hh"

Snake::Snake()
{
  this->_name = "Snake";
  this->_instructions = "move with arrow keys or zqsd\n";
  this->_map->tiles = new Position[SNAKE_MAP_WIDTH * SNAKE_MAP_HEIGHT];
  this->_map->width = SNAKE_MAP_WIDTH;
  this->_map->heigth = SNAKE_MAP_HEIGHT;
}

Snake::~Snake()
{
  delete this->_map;
}

const std::string		&Snake::getName() const
{
  return (this->_name);
}

virtual const std::string	&getInstructions() const
{
  return (this->_instructions);
}

void				Snake::startGame()
{
  for (int i = 0; i < SNAKE_MAP_WIDTH * SNAKE_MAP_HEIGHT; i++)
    this->_map->tiles[i] = arcade::TyleTipe::Empty;
  this->_player->setInitialPosition();
  gettimeofday(&this->_lastTurn);
}

void				Snake::closeGame()
{}

void				Snake::setLastCommand(const arcade::CommandType &command)
{
  (void)command;
}

const Map			&Snake::getMap()
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
