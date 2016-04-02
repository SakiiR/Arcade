//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Sat Apr  2 13:09:50 2016 Erwan Dupard
//

#include <stdlib.h>
#include <unistd.h>
#include "ArcadeCore.hh"

ArcadeCore::ArcadeCore()
{}

ArcadeCore::~ArcadeCore()
{}

// void			ArcadeCore::startArcade(const char *displayName)
// {
//   this->_loader->loadGraphicLibrary(displayName);
//   this->_loader->getDisplay()->initDisplay();
//   this->startMenu();
// }

void			displayMenu(unsigned int menuIndex, std::vector<std::string> games,
				    std::vector<std::string> displays)
{
  unsigned int			i = 0;

  system("clear");
  for (std::vector<std::string>::iterator it = games.begin(); it != games.end(); it++)
    {
      std::cout << *it;
      if (i == menuIndex)
	std::cout << " <";
      std::cout << std::endl;
      i++;
    }
  for (std::vector<std::string>::iterator it = displays.begin(); it != displays.end(); it++)
    {
      std::cout << *it;
      if (i == menuIndex)
	std::cout << " <";
      std::cout << std::endl;
      i++;
    }
}

void			ArcadeCore::menuStartLibrary(unsigned int menuIndex)
{
  std::string		libraryPath("");
  std::regex		isGameLibrary(".*games.*");
  std::regex		isGraphicLibrary(".*lib.*");
  unsigned int		i = 0;

  for (std::vector<std::string>::const_iterator it = this->_loader.getGamesPaths().begin();
       it != this->_loader.getGamesPaths().end(); it++)
    {
      if (i == menuIndex)
	libraryPath = *it;
      i++;
    }
  if (libraryPath == "")
    {
      for (std::vector<std::string>::const_iterator it = this->_loader.getDisplaysPaths().begin();
	   it != this->_loader.getDisplaysPaths().end(); it++)
	{
	  if (i == menuIndex)
	    libraryPath = *it;
	  i++;
	}
    }
  if (regex_match(libraryPath, isGameLibrary))
    {
      this->_loader.loadGameLibrary(libraryPath);
      this->startGame();
    }
  else if (regex_match(libraryPath, isGraphicLibrary))
    {
      this->_loader.loadGraphicLibrary(libraryPath);
      this->_loader.getDisplay()->initDisplay();
    }
}

void			ArcadeCore::startMenu()
{
  bool			arcadeIsOn = true;
  char			lastInput;
  unsigned int		menuIndex = 0;

  while (arcadeIsOn)
    {
      lastInput = this->_loader.getDisplay()->getLastInput();
      switch (lastInput)
	{
	case 'z' :
	  if (menuIndex > 0)
	    menuIndex--;
	  break;
	case 's' :
	  if (menuIndex < this->_loader.getGamesPaths().size() +
	      this->_loader.getDisplaysPaths().size() - 1) 
	    menuIndex++;
	  break;
	case '\r' :
	  this->menuStartLibrary(menuIndex);
	  break;
	case 0:
	  arcadeIsOn = false;
	  break;
	case 0x1b:
	  arcadeIsOn = false;
	  break;
	default:
	  break;
	}
      displayMenu(menuIndex, this->_loader.getGamesPaths(), this->_loader.getDisplaysPaths());
      usleep(50000);
    }
}

void			ArcadeCore::executeInput(char input, bool &gameIsOn)
{
  switch (input)
    {
    case 'e':
      this->_loader.loadPreviousGraphicLibrary();
      break;
    case 'r':
      this->_loader.loadNextGraphicLibrary();
      break;
    case 't':
      this->_loader.loadPreviousGameLibrary();
      break;
    case 'y':
      this->_loader.loadNextGameLibrary();
      break;
    case 'u':
      this->_loader.getGame()->resetGame();
      break;
    case 'i':
      gameIsOn = false;
      break;
    case 0:
      gameIsOn = false;
      break;
    case 0x1b:
      gameIsOn = false;
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
  const game::Tile		*tiles = map.getTiles();
  system("clear");
  for(unsigned int i = 0; i < map.getHeight() * map.getWidth(); i++)
    {
      if (tiles[i] == game::Tile::EMPTY)
  	printf("o");
      else if (tiles[i] == game::Tile::SNAKE)
  	printf("X");
      else if (tiles[i] == game::Tile::OBSTACLE)
	printf("a");
      if ((i + 1) % map.getWidth() == 0 && i != 0)
  	printf("\n");
    }
  printf("\n");
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
      if (!this->_loader.getGame()->getIfGameIsOver())
	{
	  printf("input : %2x\n", this->_loader.getDisplay()->getLastInput());
	  this->executeInput(this->_loader.getDisplay()->getLastInput(), gameIsOn);
	  this->_loader.getDisplay()->renderMap(this->_loader.getGame()->refreshAndGetMap(), 0);
	  usleep(100000);
	}
      else
	gameIsOn = false;
    }
}
