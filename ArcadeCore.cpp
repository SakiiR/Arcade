//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Thu Mar 10 19:18:15 2016 Barthelemy Gouby
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

void			ArcadeCore::startMenu()
{
  
}

void			ArcadeCore::executeInput(char input, bool gameIsOn)
{
  /*
    if (input == '2')
    {
    load previous graphic library
    }
    else if (...)
    etc...
  */
  if (input == '9')
    gameIsOn = false;
  else if (input != NUL)
    _game->sendLastInput(input);
}

void			ArcadeCore::startGame()
{
  bool			gameIsOn = true;
  CommandType		lastInput;
  
  _game->initGame();
  while (gameIsOn)
    {
      executeInput(_display->getLastInput(), gameIsOn);
      _display->renderMap(_game->getMap());
    }
  delete _game;
}

