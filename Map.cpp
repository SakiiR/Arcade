//
// Map.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 16:45:42 2016 Barthelemy Gouby
// Last update Tue Mar 15 17:33:46 2016 Barthelemy Gouby
//

#include "IGame.hh"

Map::Map(const int width, const int height)
  : _width(width), _height(height)
{
  new this->_tiles = new game::Tile[width * height];
  for (int i = 0; i < width * height; i++)
    this->_tiles[i] = game::Tile::Empty;
}

Map::~Map()
{
  delete this->tiles;
}

void			Map::changeTile(const Position &position, const nTile &type)
{
  if (position->x > this->_width || position->y > this->_height)
    throw std::out_of_range("position is out of map");
  this->_tiles[(position->y * this->_width) + position->x] = type;
}

int			Map::getWidth() const
{
  return (this->_width);
}

int			Map::getHeight() const
{
  return (this->_height);
}

Tile			*Map::getTiles() const
{
  return (this->_tiles);
}
