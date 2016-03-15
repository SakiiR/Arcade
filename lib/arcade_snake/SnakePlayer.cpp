//
// SnakePlayer.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade/lib/arcade_snake
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue Mar 15 14:02:54 2016 Barthelemy Gouby
// Last update Tue Mar 15 14:26:27 2016 Barthelemy Gouby
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

void		SnakePlayer::setInitialPosition()
{
  this->_playerBody = new Position[3];
  this->_playerBody[0]->x = SNAKE_MAP_WIDTH / 2;
  this->_playerBody[0]->y = SNAKE_MAP_HEIGHT / 2;
  this->_playerBody[1]->x = this->_playerBody[0]->x - 1;
  this->_playerBody[1]->y = this->_playerBody[0]->y;
  this->_playerBody[2]->x = this->_playerBody[1]->x - 1;
  this->_playerBody[2]->y = this->_playerBody[1]->y;
}

void		SnakePlayer::movePlayer(arcade::CommandType direction)
{

}

bool		SnakePlayer::checkIfColision(Position position)
{

}
