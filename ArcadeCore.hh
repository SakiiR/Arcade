//
// Arcade.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed Mar  9 16:23:56 2016 Barthelemy Gouby
// Last update Thu Mar 10 17:37:31 2016 Barthelemy Gouby
//

#ifndef __ARCADECORE_HH__
# define __ARCADECORE_HH__

# include <string>
# include "IDisplay.hh"
# include "IGame.hh"
# include "Loader.hh"

class					ArcadeCore
{
public:
  ArcadeCore();
  ~ArcadeCore();
  void					startArcade(const char *displayName);
  void					setGame(IGame *game);
  void					setDisplay(IDisplay *display);
  void					startMenu();
  void					startGame();
  void					executeInput(char input);
private:
  IGame					*_game;
  IDisplay				*_display;
  Loader				*_loader;
}

#ENDIF /* !__ARCADECORE_HH__ */
