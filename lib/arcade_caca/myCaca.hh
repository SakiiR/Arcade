//
// caca.hh for arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 17:55:00 2016 Erwan Dupard
// Last update Wed Mar  9 18:23:05 2016 Erwan Dupard
//

#ifndef MYCACA_HH_
# define MYCACA_HH_

# include <iostream>
# include "../../deps/caca/include/caca++.h"
# include "../../IDisplay.hh"

class				myCaca : public IDisplay
{
public:
  myCaca();
  ~myCaca();
};

#endif /* ! MYCACA_HH_ */
