//
// Ghost.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_pacman
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon Mar 28 17:28:50 2016 Barthelemy Gouby
// Last update Tue Mar 29 16:24:50 2016 Barthelemy Gouby
//

#include "Ghost.hh"

Ghost::Ghost(const game::Position initialPosition, const game::Direction initialDirection, game::Map &map)
{
  this->_ghostPosition = initialPosition;
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

void				Ghost::moveGhost(game::Map &map)
{
  std::vector<game::Direction>		directions = getPossibleDirections(map);
  std::random_device			rd;
  std::default_random_engine		generator(rd());
  std::uniform_int_distribution<int>	directionDistrib(0, directions.size() - 1);
  game::Direction			chosenDirection = directions[directionDistrib(generator)];
  game::Position			nextPosition = this->findNextPosition(chosenDirection);

  map.changeTile(nextPosition, game::Tile::GHOST);
  map.changeTile(this->_ghostPosition, game::Tile::EMPTY);
  this->_ghostPosition = nextPosition;
  this->_movementDirection = chosenDirection;
}

