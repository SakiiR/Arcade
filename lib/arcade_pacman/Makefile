##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_pacman
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:26:09 2016 Erwan Dupard
## Last update Mon Mar 28 13:02:27 2016 Barthelemy Gouby
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -fPIC -shared -W -Wall -Werror -Wextra -std=c++11

LDXXFLAGS		= 

NAME			= ../../games/libarcade_pacman.so

SRCS			= Pacman.cpp		\
			  PacmanPlayer.cpp

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
