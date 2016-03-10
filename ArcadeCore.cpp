//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Thu Mar 10 17:48:23 2016 Barthelemy Gouby
//

#include "ArcadeCore.hh"

ArcadeCore::ArcadeCore()
{
  _loader = new Loader;
}

ArcadeCore::~ArcadeCore()
{
  delete _loader;
}

void			ArcadeCore::setDisplay(IDisplay *display);
{
  _display = display;
  _display->initDisplay();
}

void			ArcadeCore::setGame(IGame *game)
{
  _game = game;
}

void			ArcadeCore::startArcade(const char *displayName);
{
  _loader->loadGraphicLibrary(displayName);
  setDisplay(_loader->getDisplay());
  startMenu();
}

void			ArcadeCore::executeInput(char input)
{
  
}

void			ArcadeCore::startGame()
{
  bool			gameIsSelected = true;
  CommandType		lastInput = NUL;

  _game->initGame();
  while (gameIsSelected)
    {
      executeInput(_display->getLastInput());
      
    }
}

