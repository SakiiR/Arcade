##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:18:51 2016 Erwan Dupard
## Last update Wed Mar 30 12:00:39 2016 Erwan Dupard
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -fPIC -shared -W -Wall -Werror -Wextra -std=c++11

CPPFLAGS		= -I../../deps/SDL2/include -L../../deps/SDL2/ -lfreetype -lSDL2_ttf -lSDL2

NAME			= ../../lib/lib_arcade_sdl2.so

SRCS			= mySDL2.cpp		\

OBJS			= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(CPPqFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
