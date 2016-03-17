//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Wed Mar 16 18:27:18 2016 Barthelemy Gouby
//

#include <stdlib.h>
#include <unistd.h>
#include "ArcadeCore.hh"

ArcadeCore::ArcadeCore()
{}

ArcadeCore::~ArcadeCore()
{}

// void			ArcadeCore::startArcade(const char *displayName);
// {
//   this->_loader->loadGraphicLibrary(displayName);
//   this->_loader->getDisplay()->initDisplay();
//   this->startMenu();
// }

void			ArcadeCore::startMenu()
{
  
}

void			ArcadeCore::executeInput(char input, bool &gameIsOn)
{
  //Absoluement hors de question baru !!!!
  if (input == '2')
    this->_loader.loadPreviousGraphicLibrary();
  else if (input == '3')
    this->_loader.loadNextGraphicLibrary();
  else if (input == '4')
    this->_loader.loadPreviousGameLibrary();
  else if (input == '5')
    this->_loader.loadNextGameLibrary();
  else if (input == '8')
    this->_loader.getGame()->resetGame();
  else if (input == '9')
    gameIsOn = false;
  else if (input != 0)
    this->_loader.getGame()->sendLastInput(input);
}

Loader				&ArcadeCore::getLoader()
{
  return (this->_loader);
}

void			displayMapTerm(const game::Map &map)
{
  game::Tile		*tiles = map.getTiles();

  system("clear");
  for(unsigned int i = 0; i < map.getHeight() * map.getWidth(); i++)
    {
      if (tiles[i] == game::Tile::EMPTY)
	printf("o");
      else if (tiles[i] == game::Tile::SNAKE)
	printf("X");
      if (i % map.getWidth() == 0)
	printf("\n");
    }
}

void			ArcadeCore::startGame()
{
  bool			gameIsOn = true;
  // while (this->_loader.getDisplay()->getLastInput() == 0)
  //   this->_loader.getDisplay()->renderTitleScreen(this->_loader.getGame()->getName(),
  // 						   this->_loader.getGame()->getInstructions());
  this->_loader.getGame()->startGame();
  while (gameIsOn)
    {
      this->executeInput(this->_loader.getDisplay()->getLastInput(), gameIsOn);
      
      displayMapTerm(this->_loader.getGame()->getMap());
      usleep(1000000);
      // this->_loader->getDisplay()->renderMap(this->_loader->getGame()->getMap());
    }
}
