//
// Score.hh for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 12:00:17 2016 Erwan Dupard
// Last update Wed Mar  9 12:25:41 2016 Erwan Dupard
//

#ifndef SCORE_HH_
# define SCORE_HH_

# include <map>
# include <fstream>
# include <iostream>
# include <cstdlib>

# define SCORE_FILE					(".scores")

class							Score
{
public:
  Score();
  ~Score();
  void							add(std::string name, unsigned int score);
private:
  std::map<std::string, int>				_scores;
  std::fstream						_file;
  void							_retreive();
  void							_sync();
};


#endif /* ! SCORE_HH_*/
