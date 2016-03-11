//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Fri Mar 11 11:45:48 2016 Erwan Dupard
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

void			ArcadeCore::setDisplay(IDisplay *display);
{
  this->_display = display;
  this->_display->initDisplay();
}

void			ArcadeCore::setGame(IGame *game)
{
  this->_game = game;
}

void			ArcadeCore::startArcade(const char *displayName);
{
  this->_loader->loadGraphicLibrary(displayName);
  this->setDisplay(this->_loader->getDisplay());
  startMenu();
}

void			ArcadeCore::executeInput(char input)
{}

void			ArcadeCore::startGame()
{
  bool			gameIsSelected = true;
  CommandType		lastInput = NUL;

  this->_game->initGame();
  while (gameIsSelected) 
    this->executeInput(this->_display->getLastInput());
}

