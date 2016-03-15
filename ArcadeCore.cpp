//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Tue Mar 15 11:34:19 2016 Barthelemy Gouby
//

#include "ArcadeCore.hh"

ArcadeCore::ArcadeCore()
{
  this->_loader = new Loader;
}

ArcadeCore::~ArcadeCore()
{
  delete this->_loader;
}

void			ArcadeCore::startArcade(const char *displayName);
{
  this->_loader->loadGraphicLibrary(displayName);
  this->_loader->getDisplay()->initDisplay();
  this->startMenu();
}

void			ArcadeCore::startMenu()
{
  
}

void			ArcadeCore::executeInput(char input, bool &gameIsOn)
{
  if (input == '2')
    this->_loader->loadPreviousGraphicLibrary();
  else if (input == '3')
    this->_loader->loadNextGraphicLibrary();
  else if (input == '4')
    this->_loader->loadPreviousGameLibrary();
  else if (input == '5')
    this->_loader->loadNextGameLibrary();
  else if (input == '8')
    this->_loader->getGame()->resetGame();
  else if (input == '9')
    gameIsOn = false
  else if (input != NUL)
    this->_loader->getGame()->sendLastInput(input);
}

void			ArcadeCore::startGame()
{
  bool			gameIsOn = true;
  
  this->_loader->getGame()->initGame();
  while (gameIsOn)
    {
      this->executeInput(this->_loader->getDisplay()->getLastInput(), gameIsOn);
      this->_loader->getDisplay()->renderMap(this->_loader->getGame()->getMap());
    }
  delete this->_game;
}
