//
// Map.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 16:45:42 2016 Barthelemy Gouby
// Last update Tue Mar 15 19:19:33 2016 Barthelemy Gouby
//

#include "IGame.hh"

game::Map::Map(const int width, const int height)
  : _width(width), _height(height)
{
  this->_tiles = new game::Tile[width * height];
  for (int i = 0; i < width * height; i++)
    this->_tiles[i] = game::Tile::EMPTY;
}

game::Map::~Map()
{
  delete[] this->_tiles;
}

void			game::Map::changeTile(const Position &position, const Tile &type)
{
  if (position.x > this->_width || position.y > this->_height)
    throw std::out_of_range("position is out of map");
  this->_tiles[(position.y * this->_width) + position.x] = type;
}

int const		&game::Map::getWidth() const
{
  return (this->_width);
}

int const		&game::Map::getHeight() const
{
  return (this->_height);
}

game::Tile		*game::Map::getTiles() const
{
  return (this->_tiles);
}
