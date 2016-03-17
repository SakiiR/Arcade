//
// SnakePlayer.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 14:02:54 2016 Barthelemy Gouby
// Last update Thu Mar 17 12:39:33 2016 Barthelemy Gouby
//

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

void		SnakePlayer::setInitialPosition(game::Map &map)
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

void		SnakePlayer::setMovementDirection(game::Direction direction)
{
  this->_movementDirection = direction;
}

bool		SnakePlayer::movePlayer(game::Map &map)
{
  game::Position	positionBefore;
  game::Position	swapBuffer;
  int		i;

  positionBefore = this->_playerBody[0];
  if (this->_movementDirection == game::Direction::UP)
    {
      if (this->_playerBody[0].y > 0)
	this->_playerBody[0].y--;
      else
	this->_playerBody[0].y = SNAKE_MAP_HEIGHT - 1;
    }
  if (this->_movementDirection == game::Direction::DOWN)
    {
      if (this->_playerBody[0].y < SNAKE_MAP_HEIGHT)
	this->_playerBody[0].y++;
      else
	this->_playerBody[0].y = 0;
    }
  if (this->_movementDirection == game::Direction::LEFT)
    {
      if (this->_playerBody[0].x > 0)
	this->_playerBody[0].x--;
      else
	this->_playerBody[0].x = SNAKE_MAP_WIDTH - 1;
    }
  if (this->_movementDirection == game::Direction::RIGHT)
    {
      if (this->_playerBody[0].x < SNAKE_MAP_WIDTH)
	this->_playerBody[0].x++;
      else
	this->_playerBody[0].x = 0;
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
  map.changeTile(positionBefore, game::Tile::EMPTY);
  return true;
}

void		SnakePlayer::incrementSize()
{

}

bool		SnakePlayer::checkIfColision(game::Position position)
{
  (void) position;
  return (true);
}
