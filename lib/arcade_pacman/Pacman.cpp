//
// Pacman.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:24:59 2016 Erwan Dupard
// Last update Mon Mar 28 16:46:13 2016 Barthelemy Gouby
//

#include "Pacman.hh"

int pacmanMap[961] =		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
				 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 2,0,2,2,2,2,0,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,0,2,2,2,2,0,2,
				 2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,
				 2,2,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,2,2,
				 2,2,2,2,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,2,2,2,2,2,
				 2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,
				 2,2,2,2,2,2,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,2,2,2,2,2,2,
				 0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,
				 2,2,2,2,2,2,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,2,2,2,2,2,2,
				 2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,
				 2,2,2,2,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,2,2,2,2,2,
				 2,2,2,2,2,2,0,2,0,2,2,2,2,2,0,2,0,2,2,2,2,2,0,2,0,2,2,2,2,2,2,
				 2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,
				 2,0,2,2,2,2,0,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,0,2,2,2,2,0,2,
				 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};

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
{
  this->_lastCommand = game::Direction::RIGHT;
  gettimeofday(&this->_lastTurn, NULL);
}

void				Pacman::resetGame()
{

}

void				Pacman::closeGame()
{}

void				Pacman::sendLastInput(const char &input)
{
  if (input == 'z')
    this->_lastCommand = game::Direction::UP;
  else if (input == 's')
    this->_lastCommand = game::Direction::DOWN;
  else if (input == 'q')
    this->_lastCommand = game::Direction::LEFT;
  else if (input == 'd')
    this->_lastCommand = game::Direction::RIGHT;
}

void				Pacman::doTurn()
{
  this->_player.setMovementDirection(this->_lastCommand, this->_map);
  this->_player.movePlayer(this->_map);
}

const game::Map			&Pacman::refreshAndGetMap()
{
  timeval			currentTime;
  long int			timeDifference;

  gettimeofday(&currentTime, NULL);
  timeDifference = (currentTime.tv_sec - this->_lastTurn.tv_sec) * 1000000
    + (currentTime.tv_usec - this->_lastTurn.tv_usec);
  if (timeDifference > PACMAN_TURN_LENGTH)
    {
      this->doTurn();
      this->_lastTurn = currentTime;
    }
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
