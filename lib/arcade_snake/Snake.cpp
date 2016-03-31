//
// Snake.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:27:46 2016 Erwan Dupard
// Last update Thu Mar 31 10:40:31 2016 Barthelemy Gouby
//

#include "Snake.hh"

Snake::Snake()
  : _map(SNAKE_MAP_WIDTH, SNAKE_MAP_HEIGHT)
{
  this->_name = "Snake";
  this->_instructions = "move with arrow keys or zqsd\n";
  this->_gameIsOver = false;
}

const std::string		&Snake::getName() const
{
  return (this->_name);
}

const std::string		&Snake::getInstructions() const
{
  return (this->_instructions);
}

void				Snake::startGame()
{
  this->_player.setInitialPosition(this->_map);
  this->_lastCommand = 0;
  gettimeofday(&this->_lastTurn, NULL);
  createPowerUp();
}

void				Snake::resetGame()
{

}

void				Snake::closeGame()
{

}

void				Snake::doTurn()
{
  if (!this->_player.movePlayer(this->_map))
    {
      this->_gameIsOver = true;
    }
  else
    {
      if (this->_map.getTileAt(this->_powerUp) != game::Tile::POWERUP)
	this->createPowerUp();
    }
}

void				Snake::createPowerUp()
{
  std::random_device			rd;
  std::default_random_engine		generator(rd());
  std::uniform_int_distribution<int>	xDistribution(0, SNAKE_MAP_WIDTH - 1);
  std::uniform_int_distribution<int>	yDistribution(0, SNAKE_MAP_HEIGHT - 1);  

  this->_powerUp.x = xDistribution(generator);
  this->_powerUp.y = yDistribution(generator);
  while (this->_map.getTileAt(this->_powerUp) != game::Tile::EMPTY)
    {
      this->_powerUp.x = xDistribution(generator);
      this->_powerUp.y = yDistribution(generator);  
    }
  this->_map.changeTile(this->_powerUp, game::Tile::POWERUP);
}

void				Snake::sendLastInput(const char &input)
{
  if (input == 'z')
    this->_player.setMovementDirection(game::Direction::UP);
  else if (input == 's')
    this->_player.setMovementDirection(game::Direction::DOWN);
  else if (input == 'q')
    this->_player.setMovementDirection(game::Direction::LEFT);
  else if (input == 'd')
    this->_player.setMovementDirection(game::Direction::RIGHT);
}

const game::Map			&Snake::refreshAndGetMap()
{
  timeval			currentTime;
  long int			timeDifference;

  gettimeofday(&currentTime, NULL);
  timeDifference = (currentTime.tv_sec - this->_lastTurn.tv_sec) * 1000000
    + (currentTime.tv_usec - this->_lastTurn.tv_usec);
  if (timeDifference > SNAKE_TURN_LENGTH)
    {
      this->doTurn();
      this->_lastTurn = currentTime;
    }
  return (this->_map);
}

const bool			&Snake::getIfGameIsOver() const
{
  return (this->_gameIsOver);
}

extern "C" void				Play()
{

  arcade::CommandType		lastInput;
  Snake				snake;

  snake.startGame();
  while (!std::cin.eof())
    {
      lastInput = (arcade::CommandType)std::cin.get();
      switch(lastInput)
	{
	case arcade::CommandType::PLAY :
	  snake.doTurn();
	  break;
	case arcade::CommandType::GO_UP :
	  snake.sendLastInput('z');
	  break;
	case arcade::CommandType::GO_DOWN :
	  snake.sendLastInput('s');
	  break;
	case arcade::CommandType::GO_LEFT :
	  snake.sendLastInput('q');
	  break;
	case arcade::CommandType::GO_RIGHT :
	  snake.sendLastInput('d');
	  break;
	case arcade::CommandType::WHERE_AM_I :
	  snake.whereAmI();
	  break;
	case arcade::CommandType::GET_MAP :
	  snake.getMap();
	  break;
	default:
	  break;
	}
    }
}

void				Snake::getMap()
{
  struct GetMap			getMap;
  const game::Tile		*mapTiles;

  getMap.type = arcade::CommandType::GET_MAP;
  getMap.width = SNAKE_MAP_WIDTH;
  getMap.height = SNAKE_MAP_HEIGHT;
  mapTiles = this->_map.getTiles();
  for (unsigned int i = 0; i < SNAKE_MAP_WIDTH * SNAKE_MAP_HEIGHT; i++)
    {
      switch (mapTiles[i])
	{
	case game::Tile::EMPTY :
	  getMap.tile[i] = arcade::TileType::EMPTY;
	  break;
	case game::Tile::OBSTACLE :
	  getMap.tile[i] = arcade::TileType::BLOCK;
	  break;
	case game::Tile::SNAKE :
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

void				Snake::whereAmI()
{
  struct WhereAmI		whereAmI;
  const game::Position		*playerBody;

  whereAmI.type = arcade::CommandType::WHERE_AM_I;
  whereAmI.length = (uint16_t)(this->_player.getLength());
  playerBody = this->_player.getBody();
  for (unsigned int i = 0; i < whereAmI.length; i++)
    {
      whereAmI.position[i].x = playerBody[i].x;
      whereAmI.position[i].y = playerBody[i].y;
    }
  std::cout.write((char*)&whereAmI, sizeof(whereAmI) - ((SNAKE_MAP_WIDTH * SNAKE_MAP_HEIGHT) - whereAmI.length));
}


extern "C" Snake		*create()
{
  return (new Snake);
}
