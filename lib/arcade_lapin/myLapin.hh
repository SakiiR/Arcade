//
// myLapin.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:51 2016 Erwan Dupard
// Last update Wed Mar  9 18:23:22 2016 Erwan Dupard
//

#ifndef MYLAPIN_HH_
# define MYLAPIN_HH_

# include <iostream>
# include "../../deps/lapin/include/lapin.h"
# include "../../IDisplay.hh"

class			        myLapin : public IDisplay
{
public:
  myLapin();
  ~myLapin();
};

#endif /* ! MYLAPIN_HH_ */
