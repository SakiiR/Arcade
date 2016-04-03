//
// myCaca.cpp for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:20:17 2016 Erwan Dupard
// Last update Sat Apr  2 13:25:15 2016 Erwan Dupard
//

#include "myCaca.hh"

myCaca::myCaca()
{}

void		myCaca::_drawShit()
{
  caca_set_color_ansi(this->_canvas, CACA_LIGHTGREEN, CACA_LIGHTRED);
  caca_put_str(this->_canvas, 37, 8,  "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
  caca_put_str(this->_canvas, 37, 9,  "░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░");
  caca_put_str(this->_canvas, 37, 10, "░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░");
  caca_put_str(this->_canvas, 37, 11, "░░▒▒▓▓▓███████████████████████▓▓▓▒▒░░");
  caca_put_str(this->_canvas, 37, 12, "░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░");
  caca_put_str(this->_canvas, 37, 13, "░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░");
  caca_put_str(this->_canvas, 37, 14, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
  caca_put_str(this->_canvas, 37, 15, "░ Arcade libcaca by Barthe && Erwan ░");
  caca_put_str(this->_canvas, 37, 16, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
  caca_put_str(this->_canvas, 37, 17, "░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░");
  caca_put_str(this->_canvas, 37, 18, "░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░");
  caca_put_str(this->_canvas, 37, 19, "░░▒▒▓▓▓███████████████████████▓▓▓▒▒░░");
  caca_put_str(this->_canvas, 37, 20, "░░▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒░░");
  caca_put_str(this->_canvas, 37, 21, "░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░");
  caca_put_str(this->_canvas, 37, 22, "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");
}

void		myCaca::initDisplay()
{
  if ((this->_display = caca_create_display(NULL)) != NULL)
    {
      this->_canvas = caca_get_canvas(this->_display);      
      caca_set_display_title(this->_display, "Arcade ! C++ LibCaca");
      this->_drawShit();
    }
}

void		myCaca::closeDisplay()
{
  caca_free_display(this->_display);
}

void		myCaca::renderTitleScreen(const std::string &gameTitle, const std::string &instructions)
{
  (void)gameTitle;
  (void)instructions;
}

void		myCaca::renderMap(const game::Map &map, char c)
{
  (void)c;
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
	  caca_set_color_ansi(this->_canvas, CACA_LIGHTRED, CACA_LIGHTGREEN);
	  break;
	case game::Tile::POWERUP:
	  caca_set_color_ansi(this->_canvas, CACA_BLUE, CACA_BLACK);
  	  break;
	case game::Tile::OBSTACLE:
	  caca_set_color_ansi(this->_canvas, CACA_GREEN, CACA_BLUE);
  	  break;
	case game::Tile::PACMAN:
	  caca_set_color_ansi(this->_canvas, CACA_BLUE, CACA_GREEN);
  	  break;
	case game::Tile::GHOST:
	  caca_set_color_ansi(this->_canvas, CACA_RED, CACA_WHITE);
  	  break;
 	case game::Tile::HUNTED_GHOST:
	  caca_set_color_ansi(this->_canvas, CACA_GREEN, CACA_GREEN);
	  break;
  	default:
	  caca_set_color_ansi(this->_canvas, CACA_LIGHTGREEN, CACA_LIGHTRED);
	  break;
  	}
      caca_put_str(this->_canvas, p.x, p.y, "°");
      ++i;
    }
  caca_refresh_display(this->_display);
}

void		myCaca::renderMenu(const MenuState &menuState)
{
  (void)menuState;
}

char		myCaca::getLastInput()
{
  caca_get_event(this->_display, CACA_EVENT_KEY_PRESS, &this->_event, 0);
  if (caca_get_event_type(&this->_event) & CACA_EVENT_KEY_PRESS)
    return (caca_get_event_key_ch(&this->_event));
  return (0x1);
}

void		myCaca::cleanScreen()
{
  unsigned int	x = 0;
  unsigned int	y;

  caca_set_color_ansi(this->_canvas, CACA_LIGHTGREEN, CACA_LIGHTRED);
  while (x < 80)
    {
      y = 0;
      while (y < 80)
	{
	  caca_put_str(this->_canvas, x, y, " ");
	  y++;
	}
      ++x;
    }
  this->_drawShit();
}

extern "C" myCaca	*create()
{
  return (new myCaca);
}
