//
// myLapin.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:21:59 2016 Erwan Dupard
// Last update Sat Apr  2 13:08:00 2016 Erwan Dupard
//

#include "myLapin.hh"

t_bunny_response		my_keyevent(t_bunny_event_state state, t_bunny_keysym key, void *data)
{
  myLapin			*lapin = (myLapin *)data;

  (void)state;
  if (key >= BKS_A && key <= BKS_Z)
    lapin->setLastKey((char)key + 0x61);
  else if (key == BKS_RETURN)
    lapin->setLastKey(0x0d);
  else
    lapin->setLastKey((char)key);
  return (EXIT_ON_SUCCESS);
}

t_bunny_response		my_loop(void *data)
{
  (void)data;
  return (EXIT_ON_SUCCESS);
}

myLapin::myLapin()
{
  this->_window = NULL;
  this->_lastKey = 0x10;
  bunny_set_loop_main_function(&my_loop);
  bunny_set_key_response(&my_keyevent);
}

void				myLapin::initDisplay()
{
  if ((this->_window = bunny_start(SCREEN_X, SCREEN_Y, false, this->_name.c_str())) != NULL)
    {
      bunny_display(this->_window);
      this->_screen = bunny_new_pixelarray(SCREEN_X, SCREEN_Y);
    }
}

void				myLapin::closeDisplay()
{
  bunny_stop(this->_window);
  bunny_delete_clipable(&this->_screen->clipable);
}

void				myLapin::renderTitleScreen(const std::string &gameTitle, const std::string &instructions)
{
  (void)gameTitle;
  (void)instructions;
}

void				myLapin::_updateWindow()
{
  t_bunny_position		position;

  position.x = 0;
  position.y = 0;
  bunny_blit(&this->_window->buffer, &this->_screen->clipable, &position);
  bunny_display(this->_window);
}

void				myLapin::renderMap(const game::Map &map, char c)
{
  (void)c;
  game::Position	tileSize(SCREEN_X / map.getWidth(), SCREEN_Y / map.getHeight());
  unsigned int		i = 0;
  const game::Tile	*tiles = map.getTiles();
  game::Position	p(0, 0);

  while (i < map.getWidth() * map.getHeight())
    {
      p.y = (i == 0 ? 0 : i / map.getWidth());
      p.x = i - (p.y * map.getWidth());
      switch (tiles[i])
  	{
  	case game::Tile::SNAKE:
  	  this->_writeTile(p, tileSize, SNAKE_COLOR);
	  break;
	case game::Tile::POWERUP:
	  this->_writeTile(p, tileSize, POWERUP_COLOR);
  	  break;
	case game::Tile::OBSTACLE:
	  this->_writeTile(p, tileSize, OBSTACLE_COLOR);
  	  break;
	case game::Tile::PACMAN:
	  this->_writeTile(p, tileSize, OBSTACLE_COLOR);
	  break;
	case game::Tile::GHOST:
	  this->_writeTile(p, tileSize, GHOST_COLOR);
	  break;
	case game::Tile::HUNTED_GHOST:
	  this->_writeTile(p, tileSize, WEAKGHOST_COLOR);
	  break;
  	default:
  	  this->_writeTile(p, tileSize, VOID_COLOR);
	  break;
  	}
      ++i;
    }
  this->_updateWindow();
}

void		        myLapin::_writeTile(const game::Position &position, const game::Position &size, unsigned int color)
{
  unsigned		*pixels = (unsigned *)this->_screen->pixels;
  unsigned int		start;
  unsigned int		save;
  unsigned int		i;
  
  start = ((SCREEN_X * position.y * size.y) + (size.x * position.x));
  save = start;
  if (pixels[start + (SCREEN_X * 2)] != color)
    {
      while (start <= (save + (size.y * SCREEN_X)))
      	{
      	  i = start;
      	  while (i < (start + size.x))
      	    {
      	      pixels[i] = color;
      	      ++i;
      	    }
      	  start += SCREEN_X;
      	}
    }
}

void			myLapin::renderMenu(const MenuState &menuState)
{
  (void)menuState;
}

void			myLapin::cleanScreen()
{
  unsigned		*pixels = (unsigned *)this->_screen->pixels;
  unsigned int		i = 0;

  while (i < SCREEN_X * SCREEN_Y)
    {
      pixels[i] = VOID_COLOR;
      ++i;
    }
  this->_updateWindow();
}

char			myLapin::getLastInput()
{
  bunny_loop(this->_window, 100, (void *)this);
  return (this->_lastKey);
}

void			myLapin::setLastKey(char c)
{
  this->_lastKey = c;
}

extern "C" IDisplay	*create()
{
  return (new myLapin);
}
