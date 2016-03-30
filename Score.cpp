//
// Score.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 12:00:46 2016 Erwan Dupard
// Last update Wed Mar 30 11:34:42 2016 Erwan Dupard
//

#include "Score.hh"

Score::Score()
{
  std::cout << "[^] Openning score file" << std::endl;
  this->_file.open(SCORE_FILE, std::fstream::in | std::fstream::out | std::fstream::trunc);
  if (!this->_file.is_open())
    std::cout << "[-] Can't use Score Module.. Can't open file " << SCORE_FILE << std::endl;
  this->_retreive();
}

Score::~Score()
{
  this->_sync();
  this->_file.close();
}

void								Score::add(std::string name, unsigned int score)
{
  this->_scores[name] = score;
}

void								Score::_retreive()
{
  std::string							line;
  std::string							score;

  if (this->_file.is_open())
    {
      while (std::getline(this->_file, line))
	{
	  score = line.substr(line.find(":") + 1, line.size() - 1);
	  this->_scores[line.substr(0, line.find(":"))] = std::atoi(score.c_str());
	}
    }
}

void								Score::_sync()
{
  std::map<std::string, unsigned int>::iterator			it = this->_scores.begin();
  
  if (this->_file.is_open())
    {
      std::cout << "[^] Sync scores .." << std::endl;
      this->_file.close();
      this->_file.open(SCORE_FILE, std::ofstream::out | std::ofstream::trunc);
      while (it != this->_scores.end())
	{
	  this->_file << it->first << ":" << it->second << std::endl;
	  it++;
	}
    }
}

unsigned int							Score::get(const std::string &name) const
{
  std::map<std::string, unsigned int>::const_iterator		it;

  it = this->_scores.find(name);
  if (it != this->_scores.end())
    return (it->second);
  return (0);
}
