##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:26:09 2016 Erwan Dupard
## Last update Thu Mar 31 10:35:18 2016 Barthelemy Gouby
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -fPIC -shared -W -Wall -Werror -Wextra -std=c++11 -g -g3 -ggdb

LDXXFLAGS		= 

NAME			= ../../games/lib_arcade_pacman.so

SRCS			= Pacman.cpp		\
			  PacmanPlayer.cpp	\
			  Ghost.cpp		\
			  ../../Map.cpp

OBJS			= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
