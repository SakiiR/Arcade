##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:18:51 2016 Erwan Dupard
## Last update Fri Apr  1 18:18:48 2016 Barthelemy Gouby
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -shared -W -Wall -Werror -Wextra -std=c++11

CPPFLAGS		= -shared -fPIC -I../../deps/SDL2/include -L../../deps/SDL2/ -Wl,--whole-archive ../../deps/SDL2/libSDL2_ttf.a -Wl,--no-whole-archive -lSDL2

NAME			= ../../lib/lib_arcade_sdl2.so

SRCS			= mySDL2.cpp		\

OBJS			= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(CPPFLAGS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
