//
// Ghost.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon Mar 28 17:28:50 2016 Barthelemy Gouby
// Last update Thu Mar 31 16:09:44 2016 Barthelemy Gouby
//

#include "Ghost.hh"

Ghost::Ghost(const game::Position initialPosition, const game::Direction initialDirection, game::Map &map)
{
  this->_isDead = false;
  this->_initialPosition = initialPosition;
  this->_ghostPosition = initialPosition;
  this->_savedTile = game::Tile::EMPTY;
  this->_huntedMove = true;
  map.changeTile(initialPosition, game::Tile::GHOST);
  this->_movementDirection = initialDirection;
}

Ghost::~Ghost()
{
  
}

game::Position			Ghost::findNextPosition(const game::Direction &direction) const
{
  game::Position		newPosition;

  newPosition = this->_ghostPosition;
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

std::vector<game::Direction>	Ghost::getPossibleDirections(const game::Map &map) const
{
  std::vector<game::Direction>	directions;

  if (this->_movementDirection != game::Direction::DOWN &&
      map.getTileAt(this->findNextPosition(game::Direction::UP)) != game::Tile::OBSTACLE)
    directions.push_back(game::Direction::UP);
  if (this->_movementDirection != game::Direction::UP &&
      map.getTileAt(this->findNextPosition(game::Direction::DOWN)) != game::Tile::OBSTACLE)
    directions.push_back(game::Direction::DOWN);
  if (this->_movementDirection != game::Direction::LEFT &&
      map.getTileAt(this->findNextPosition(game::Direction::RIGHT)) != game::Tile::OBSTACLE)
    directions.push_back(game::Direction::RIGHT);
  if (this->_movementDirection != game::Direction::RIGHT &&
      map.getTileAt(this->findNextPosition(game::Direction::LEFT)) != game::Tile::OBSTACLE)
    directions.push_back(game::Direction::LEFT);
  return (directions);
}

bool				Ghost::getIfDead()
{
  return (this->_isDead);
}

timeval				&Ghost::getTimeOfDeath()
{
  return (this->_timeOfDeath);
}

void				Ghost::reviveGhost()
{
  this->_isDead = false;
  this->_ghostPosition = this->_initialPosition;
  this->_savedTile = game::Tile::EMPTY;
}

void				Ghost::moveGhost(game::Map &map, bool &gameIsOver, bool &hunter)
{
  std::vector<game::Direction>		directions = getPossibleDirections(map);
  std::random_device			rd;
  std::default_random_engine		generator(rd());
  std::uniform_int_distribution<int>	directionDistrib(0, directions.size() - 1);
  game::Direction			chosenDirection = directions[directionDistrib(generator)];
  game::Position			nextPosition = this->findNextPosition(chosenDirection);

  if (hunter == false && map.getTileAt(this->_ghostPosition) == game::Tile::PACMAN)
    {
      this->_isDead = true;
      gettimeofday(&(this->_timeOfDeath), NULL);
    }
  else if (hunter == true || (hunter == false && this->_huntedMove == true))
    {
      if (map.getTileAt(nextPosition) == game::Tile::PACMAN)
	{
	  if (hunter == true)
	    gameIsOver = true;
	  else
	    this->_isDead = true;
	}
      map.changeTile(this->_ghostPosition, this->_savedTile);
      this->_savedTile = map.getTileAt(nextPosition);
      if (this->_savedTile == game::Tile::GHOST || this->_savedTile == game::Tile::HUNTED_GHOST)
	this->_savedTile = game::Tile::EMPTY;
      if (hunter == true)
	map.changeTile(nextPosition, game::Tile::GHOST);
      else
	map.changeTile(nextPosition, game::Tile::HUNTED_GHOST);
      this->_ghostPosition = nextPosition;
      this->_movementDirection = chosenDirection;
    }
  if (hunter == false)
    this->_huntedMove = !(this->_huntedMove);
}
