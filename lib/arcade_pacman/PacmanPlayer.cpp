//
// PacmanPlayer.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Sat Mar 26 07:34:53 2016 Barthelemy Gouby
// Last update Thu Mar 31 10:31:57 2016 Barthelemy Gouby
//

#include "PacmanPlayer.hh"

PacmanPlayer::PacmanPlayer()
{
  this->_playerPosition.x = PACMAN_MAP_WIDTH / 2;
  this->_playerPosition.y = PACMAN_MAP_HEIGHT / 2 - 3;
  this->_movementDirection = game::Direction::RIGHT;
}

PacmanPlayer::~PacmanPlayer()
{}

void			PacmanPlayer::setMovementDirection(const game::Direction &direction, const game::Map &map)
{
  const game::Tile	&testTile = map.getTileAt(this->findNextPosition(direction));
  
  if (testTile != game::Tile::OBSTACLE)
    this->_movementDirection = direction;
}

game::Position		PacmanPlayer::findNextPosition(const game::Direction &direction)
{
  game::Position	newPosition;

  newPosition = this->_playerPosition;
  switch (direction)
    {
    case game::Direction::UP :
      newPosition.y > 0 ? newPosition.y-- : newPosition.y = PACMAN_MAP_HEIGHT - 1;
      break;
    case game::Direction::DOWN :
      newPosition.y < PACMAN_MAP_HEIGHT - 1 ? newPosition.y++ : newPosition.y = 0;
      break;
    case game::Direction::LEFT :
      newPosition.x > 0 ? newPosition.x-- : newPosition.x = PACMAN_MAP_WIDTH - 1;
      break;
    case game::Direction::RIGHT :
      newPosition.x < PACMAN_MAP_WIDTH - 1 ? newPosition.x++ : newPosition.x = 0;
      break;
    default :
      break;
    }
  return (newPosition);
}

void			PacmanPlayer::movePlayer(game::Map &map, bool &gameIsOver,
						 bool &hunted, timeval &powerBeginTime)
{
  game::Position	newPosition;

  newPosition = this->findNextPosition(this->_movementDirection);
  if (map.getTileAt(newPosition) != game::Tile::OBSTACLE)
    {
      map.changeTile(this->_playerPosition, game::Tile::EMPTY);
      if (map.getTileAt(newPosition) == game::Tile::GHOST)
	{
	  if (hunted == true)
	    gameIsOver = true;
	}
      if (map.getTileAt(newPosition) == game::Tile::POWERUP)
	{
	  hunted = false;
	  gettimeofday(&powerBeginTime, NULL);
	}
      map.changeTile(newPosition, game::Tile::PACMAN);
      this->_playerPosition = newPosition;
    }
}

game::Position	&PacmanPlayer::getPosition()
{
  return (this->_playerPosition);
}
