//
// Pacman.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:24:59 2016 Erwan Dupard
// Last update Thu Mar 31 16:06:07 2016 Barthelemy Gouby
//

#include "Pacman.hh"

int pacmanMap[961] =		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
				 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,2,
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
				 2,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,2,2,2,2,0,2,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,2,0,2,2,2,2,0,2,
				 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
				 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};

Pacman::Pacman()
  : _map(PACMAN_MAP_WIDTH, PACMAN_MAP_HEIGHT, pacmanMap)
{
  this->_name = "libsnake";
  this->_gameIsOver = false;
  this->_victory = false;
  this->_pacmanHunted = true;
  this->_ghosts.push_back(Ghost(game::Position(PACMAN_MAP_WIDTH / 2 - 3, PACMAN_MAP_HEIGHT / 2 - 3),
				game::Direction::LEFT, this->_map));
  this->_ghosts.push_back(Ghost(game::Position(PACMAN_MAP_WIDTH / 2 + 3, PACMAN_MAP_HEIGHT / 2 - 3),
				game::Direction::RIGHT, this->_map));
  this->_ghosts.push_back(Ghost(game::Position(PACMAN_MAP_WIDTH / 2 - 5, PACMAN_MAP_HEIGHT / 2 - 3),
				game::Direction::LEFT, this->_map));
  this->_ghosts.push_back(Ghost(game::Position(PACMAN_MAP_WIDTH / 2 + 5, PACMAN_MAP_HEIGHT / 2 - 3),
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
  timeval			currentTime;
  long int			deathTimeDifference;

  gettimeofday(&currentTime, NULL);
  this->_player.setMovementDirection(this->_lastCommand, this->_map);
  this->_player.movePlayer(this->_map, this->_gameIsOver, this->_pacmanHunted, this->_powerBeginTime);
  for (std::vector<Ghost>::iterator it = this->_ghosts.begin(); it != this->_ghosts.end(); it++)
    {
      if ((*it).getIfDead() != true)
	(*it).moveGhost(this->_map, this->_gameIsOver, this->_pacmanHunted);
      else
	{
	  deathTimeDifference = (currentTime.tv_sec - (*it).getTimeOfDeath().tv_sec) * 1000000
	    + (currentTime.tv_usec - (*it).getTimeOfDeath().tv_usec);
	  if (deathTimeDifference > GHOST_DEATH_DURATION)
	    (*it).reviveGhost();
	}
    }
  this->testIfVictory();
}

const game::Map			&Pacman::refreshAndGetMap()
{
  timeval			currentTime;
  long int			turnTimeDifference;
  long int			powerTimeDifference;

  gettimeofday(&currentTime, NULL);
  turnTimeDifference = (currentTime.tv_sec - this->_lastTurn.tv_sec) * 1000000
    + (currentTime.tv_usec - this->_lastTurn.tv_usec);
  if (this->_pacmanHunted == false)
    {
      powerTimeDifference = (currentTime.tv_sec - this->_powerBeginTime.tv_sec) * 1000000
	+ (currentTime.tv_usec - this->_powerBeginTime.tv_usec);
      if (powerTimeDifference > PACMAN_POWERUP_LENGTH)
	this->_pacmanHunted = true;
    }
  if (turnTimeDifference > PACMAN_TURN_LENGTH)
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

void				Pacman::testIfVictory()
{
  unsigned int i;

  for (i = 0; i < PACMAN_MAP_HEIGHT * PACMAN_MAP_WIDTH; i++)
    {
      if (this->_map.getTiles()[i] == game::Tile::PACGUM || this->_map.getTiles()[i] == game::Tile::POWERUP)
	break;
    }
  if (i == PACMAN_MAP_HEIGHT * PACMAN_MAP_WIDTH)
    {
      this->_victory = true;
      this->_gameIsOver = true;
    }
}


extern "C" void				Play()
{

  arcade::CommandType		lastInput;
  Pacman			pacman;

  pacman.startGame();
  while (!std::cin.eof())
    {
      lastInput = (arcade::CommandType)std::cin.get();
      switch(lastInput)
	{
	case arcade::CommandType::PLAY :
	  pacman.doTurn();
	  break;
	case arcade::CommandType::GO_UP :
	  pacman.sendLastInput('z');
	  break;
	case arcade::CommandType::GO_DOWN :
	  pacman.sendLastInput('s');
	  break;
	case arcade::CommandType::GO_LEFT :
	  pacman.sendLastInput('q');
	  break;
	case arcade::CommandType::GO_RIGHT :
	  pacman.sendLastInput('d');
	  break;
	case arcade::CommandType::WHERE_AM_I :
	  pacman.whereAmI();
	  break;
	case arcade::CommandType::GET_MAP :
	  pacman.getMap();
	  break;
	default:
	  break;
	}
    }
}

void				Pacman::getMap()
{
  struct GetMap			getMap;
  const game::Tile		*mapTiles;

  getMap.type = arcade::CommandType::GET_MAP;
  getMap.width = PACMAN_MAP_WIDTH;
  getMap.height = PACMAN_MAP_HEIGHT;
  mapTiles = this->_map.getTiles();
  for (unsigned int i = 0; i < PACMAN_MAP_WIDTH * PACMAN_MAP_HEIGHT; i++)
    {
      switch (mapTiles[i])
	{
	case game::Tile::EMPTY :
	  getMap.tile[i] = arcade::TileType::EMPTY;
	  break;
	case game::Tile::OBSTACLE :
	  getMap.tile[i] = arcade::TileType::BLOCK;
	  break;
	case game::Tile::PACMAN :
	  getMap.tile[i] = arcade::TileType::EMPTY;
	  break;
	case game::Tile::POWERUP :
	  getMap.tile[i] = arcade::TileType::POWERUP;
	  break;
	default :
	  break;
	}
    }
  std::cout.write((char*)(&getMap), sizeof(getMap));
}

void				Pacman::whereAmI()
{
  struct WhereAmI		whereAmI;

  whereAmI.type = arcade::CommandType::WHERE_AM_I;
  whereAmI.length = 1;
  whereAmI.position[0].x = this->_player.getPosition().x;
  whereAmI.position[0].y = this->_player.getPosition().y;
  std::cout.write((char*)&whereAmI, sizeof(whereAmI));
}

extern "C" Pacman		*create()
{
  return (new Pacman);
}
