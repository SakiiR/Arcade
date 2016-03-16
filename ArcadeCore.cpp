//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Wed Mar 16 22:54:12 2016 Erwan Dupard
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
  switch (input)
    {
    case '2':
      this->_loader.loadPreviousGraphicLibrary();
      break;
    case '3':
      this->_loader.loadNextGraphicLibrary();
      break;
    case '4':
      this->_loader.loadPreviousGameLibrary();
      break;
    case '5':
      this->_loader.loadNextGameLibrary();
      break;
    case '8':
      this->_loader.getGame()->resetGame();
      break;
    case '9':
      gameIsOn = false;
      break;
    case 0:
      // on fait quoi quand c'est zero ?
      break;
    default:
      this->_loader.getGame()->sendLastInput(input);
      break;
    }
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
      // this->executeInput(this->_loader.getDisplay()->getLastInput(), gameIsOn);
      printf("input:     %c\n", this->_loader.getDisplay()->getLastInput());
      // displayMapTerm(this->_loader.getGame()->getMap());
      usleep(1000000);
      // this->_loader->getDisplay()->renderMap(this->_loader->getGame()->getMap());
    }
}
