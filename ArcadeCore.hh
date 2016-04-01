//
// Arcade.hh for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed Mar  9 16:23:56 2016 Barthelemy Gouby
// Last update Fri Apr  1 15:17:26 2016 Barthelemy Gouby
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
  // void					startArcade(const char *displayName);
  void					startMenu();
  void					menuStartLibrary(unsigned int menuIndex);
  void					startGame();
  void					executeInput(char input, bool &gameIsOn);
  Loader				&getLoader();
private:
  Loader				_loader;
};

#endif /* !__ARCADECORE_HH__ */
