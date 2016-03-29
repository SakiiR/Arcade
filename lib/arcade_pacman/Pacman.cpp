//
// Pacman.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:24:59 2016 Erwan Dupard
// Last update Tue Mar 29 16:36:36 2016 Barthelemy Gouby
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
  this->_ghosts.push_back(Ghost(game::Position(PACMAN_MAP_WIDTH / 2 - 3, PACMAN_MAP_HEIGHT / 2 - 3),
				game::Direction::LEFT, this->_map));
  this->_ghosts.push_back(Ghost(game::Position(PACMAN_MAP_WIDTH / 2 + 3, PACMAN_MAP_HEIGHT / 2 - 3),
				game::Direction::RIGHT, this->_map));
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
  this->_player.movePlayer(this->_map, this->_gameIsOver);
  for (unsigned int i = 0; i < this->_ghosts.size(); i++)
    this->_ghosts[i].moveGhost(this->_map, this->_gameIsOver);
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
