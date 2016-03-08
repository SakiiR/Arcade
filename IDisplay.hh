//
// IDisplay.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 16:36:09 2016 Erwan Dupard
// Last update Tue Mar  8 16:48:25 2016 Barthelemy Gouby
//

#ifndef IDISPLAY_HH_
# define IDISPLAY_HH_

# include <string>

class			IDisplay
{
public:
  virtual std::string const	getName() const = 0;
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderWindow() = 0;
  // etc etc 
};

#endif /* ! IDISPLAY_HH_ */
