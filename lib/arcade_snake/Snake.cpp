//
// Snake.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:27:46 2016 Erwan Dupard
// Last update Tue Mar 15 18:20:28 2016 Barthelemy Gouby
//

#include "Snake.hh"

Snake::Snake()
  : _map(SNAKE_MAP_WIDTH, SNAKE_MAP_HEIGHT)
{
  this->_name = "Snake";
  this->_instructions = "move with arrow keys or zqsd\n";
}

const std::string		&Snake::getName() const
{
  return (this->_name);
}

const std::string		&Snake::getInstructions() const
{
  return (this->_instructions);
}

void				Snake::startGame()
{
  this->_player.setInitialPosition();
  this->_lastCommand = 0;
  gettimeofday(&this->_lastTurn, NULL);
}

void				Snake::closeGame()
{}

void				Snake::doTurn()
{

}

void				sendLastInput(const char &input)
{
  (void)input;
}

const game::Map			&Snake::getMap()
{
  timeval			currentTime;

  gettimeofday(&currentTime, NULL);
  if ((currentTime.tv_usec - this->_lastTurn.tv_usec) > SNAKE_TURN_LENGTH)
    {
      this->doTurn();
      this->_lastTurn = currentTime;
    }
  return (this->_map);
}

void				Snake::Play()
{}

extern "C" Snake		*create()
{
  return (new Snake);
}
