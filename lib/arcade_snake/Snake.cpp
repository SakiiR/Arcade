//
// Snake.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:27:46 2016 Erwan Dupard
// Last update Thu Mar 17 11:50:03 2016 Barthelemy Gouby
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
  this->_player.setInitialPosition(this->_map);
  this->_lastCommand = 0;
  gettimeofday(&this->_lastTurn, NULL);
}

void				Snake::resetGame()
{

}

void				Snake::closeGame()
{}

void				Snake::doTurn()
{
  printf("doin turn\n");
  this->_player.movePlayer(this->_map);
}

void				Snake::sendLastInput(const char &input)
{
  if (input == 'z')
    this->_player.setMovementDirection(game::Direction::UP);
  else if (input == 's')
    this->_player.setMovementDirection(game::Direction::DOWN);
  else if (input == 'q')
    this->_player.setMovementDirection(game::Direction::LEFT);
  else if (input == 'd')
    this->_player.setMovementDirection(game::Direction::RIGHT);
}

const game::Map			&Snake::getMap()
{
  timeval			currentTime;
  long int			timeDifference;

  gettimeofday(&currentTime, NULL);
  timeDifference = (currentTime.tv_sec - this->_lastTurn.tv_sec) * 1000000 + (currentTime.tv_usec - this->_lastTurn.tv_usec);
  printf("time diff :%li\n", timeDifference);
  if (timeDifference > SNAKE_TURN_LENGTH)
    {
      printf("doin turn yo\n");
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
