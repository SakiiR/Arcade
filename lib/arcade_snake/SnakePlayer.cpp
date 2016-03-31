//
// SnakePlayer.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 14:02:54 2016 Barthelemy Gouby
// Last update Wed Mar 30 18:55:35 2016 Barthelemy Gouby
//

#include <iostream>
#include "SnakePlayer.hh"

SnakePlayer::SnakePlayer()
{
  this->_playerBody = NULL;
}

SnakePlayer::~SnakePlayer()
{
  if (this->_playerBody != NULL)
    delete this->_playerBody;
}

void			SnakePlayer::setInitialPosition(game::Map &map)
{
  this->_playerBody = new game::Position[3];
  this->_playerBody[0].x = SNAKE_MAP_WIDTH / 2;
  this->_playerBody[0].y = SNAKE_MAP_HEIGHT / 2;
  map.changeTile(game::Position(this->_playerBody[0].x, this->_playerBody[0].y), game::Tile::SNAKE);
  this->_playerBody[1].x = this->_playerBody[0].x - 1;
  this->_playerBody[1].y = this->_playerBody[0].y;
  map.changeTile(game::Position(this->_playerBody[1].x, this->_playerBody[1].y), game::Tile::SNAKE);
  this->_playerBody[2].x = this->_playerBody[1].x - 1;
  this->_playerBody[2].y = this->_playerBody[1].y;
  map.changeTile(game::Position(this->_playerBody[2].x, this->_playerBody[2].y), game::Tile::SNAKE);
  this->_playerLength = SNAKE_PLAYER_INITIAL_LENGTH;
  this->_movementDirection = game::Direction::RIGHT;
}

void			SnakePlayer::setMovementDirection(game::Direction direction)
{
  if (!((this->_movementDirection == game::Direction::RIGHT && direction == game::Direction::LEFT)
	|| (this->_movementDirection == game::Direction::LEFT && direction == game::Direction::RIGHT)
	|| (this->_movementDirection == game::Direction::UP && direction == game::Direction::DOWN)
	|| (this->_movementDirection == game::Direction::DOWN && direction == game::Direction::UP)))
    this->_movementDirection = direction;
}

bool			SnakePlayer::movePlayer(game::Map &map)
{
  game::Position	positionBefore;
  game::Position	swapBuffer;
  bool			incremented = false;
  size_t		i;

  positionBefore = this->_playerBody[0];
  switch (this->_movementDirection)
    {
    case game::Direction::UP :
      this->_playerBody[0].y > 0 ? this->_playerBody[0].y-- : this->_playerBody[0].y = SNAKE_MAP_HEIGHT - 1;
      break;
    case game::Direction::DOWN :
      this->_playerBody[0].y < SNAKE_MAP_HEIGHT - 1 ? this->_playerBody[0].y++ : this->_playerBody[0].y = 0;
      break;
    case game::Direction::LEFT :
      this->_playerBody[0].x > 0 ? this->_playerBody[0].x-- : this->_playerBody[0].x = SNAKE_MAP_WIDTH - 1;
      break;
    case game::Direction::RIGHT :
      this->_playerBody[0].x < SNAKE_MAP_WIDTH - 1 ? this->_playerBody[0].x++ : this->_playerBody[0].x = 0;
      break;
    default :
      break;
    }
  if (map.getTileAt(this->_playerBody[0]) == game::Tile::POWERUP)
    {
      incremented = true;
      this->incrementSize();
    }
  if (map.getTileAt(this->_playerBody[0]) == game::Tile::SNAKE)
    return false;
  for (i = 1; i < this->_playerLength; i++)
    {
      swapBuffer = this->_playerBody[i];
      this->_playerBody[i] = positionBefore;
      positionBefore = swapBuffer;
    }
  map.changeTile(this->_playerBody[0], game::Tile::SNAKE);
  if (!incremented)
    map.changeTile(positionBefore, game::Tile::EMPTY);
  return true;
}

void			SnakePlayer::incrementSize()
{
  game::Position	*newBody = new game::Position[this->_playerLength + 1];

  for (size_t i = 0; i < this->_playerLength; i++)
    {
      newBody[i] = this->_playerBody[i];
    }
  this->_playerBody = newBody;
  this->_playerLength++;
}

const size_t		&SnakePlayer::getLength() const
{
  return (this->_playerLength);
}

const game::Position	*SnakePlayer::getBody() const
{
  return (this->_playerBody);
}
