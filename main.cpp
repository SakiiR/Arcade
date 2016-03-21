//
// main.cpp for arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 14:40:10 2016 Erwan Dupard
// Last update Mon Mar 21 11:36:20 2016 Barthelemy Gouby
//

#include "ressources.hh"
#include "ArcadeCore.hh"

void			usage(const char *execName)
{
  std::cout << "//" << std::endl;
  std::cout << "//     _____                            .___" << std::endl;      
  std::cout << "//    /  _  \\_______   ____ _____     __| _/____" << std::endl;
  std::cout << "//   /  /_\\  \\_  __ \\_/ ___\\\\__  \\   / __ |/ __ \\ " << std::endl;
  std::cout << "//  /    |    \\  | \\/\\  \\___ / __ \\_/ /_/ \\  ___/ " << std::endl;
  std::cout << "//  \\____|__  /__|    \\___  >____  /\\____ |\\___ >" << std::endl;
  std::cout << "//   \\/            \\/     \\/      \\/    \\/ " << std::endl;
  std::cout << "//" << std::endl;
  std::cout << "// [*] Usage : " << execName << " <libraryName>" << std::endl; 
  std::cout << "// [*] You can find graphic libraries in ./lib/ directory." << std::endl;
  std::cout << "// [*] Arcade by dupard_e && barthe_g" << std::endl;
  std::cout << "//" << std::endl;
}

int		main()
{
  ArcadeCore		arcade;

  arcade.getLoader().loadGameLibrary("./games/libarcade_snake.so");
  arcade.getLoader().loadGraphicLibrary("./lib/libarcade_sdl2.so");
  arcade.getLoader().getDisplay()->initDisplay();
  arcade.startGame();
}

// int			main(int argc, char **argv)
// {

//   Loader		loader;
//   IDisplay		*display;
//   unsigned char		e;
//   bool			quit = false;

//   if (argc < 2)
//     {
//       usage(argv[0]);
//       return (RETURN_SUCCESS);
//     }
//   if (loader.loadGraphicLibrary(std::string(argv[1])) == false)
//     {
//       std::cerr << "[-] Errors occured ! Maybe the library is imcompatible !" << std::endl;
//       return (RETURN_FAILURE);
//     }
//   display = loader.getDisplay();
//   display->initDisplay();
//   while (!quit)
//     {
//       e = display->getLastInput();
//       quit = (e == 0 || e == 0x1b ? true : false);
//       if (e != UNDEFINED_KEY_INPUT)
// 	printf("KEY : 0x%x\n", e);      
//     }
//   return (RETURN_SUCCESS);
// }
