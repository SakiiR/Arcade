##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Mar  8 14:37:11 2016 Erwan Dupard
## Last update Thu Mar 31 15:03:34 2016 Barthelemy Gouby
##

CC		= g++

RM		= rm -f

NAME		= arcade

CXXFLAGS	+= -g3 -Wall -Werror -W -Wextra -std=c++11 -rdynamic -fPIC

LDXXFLAGS	+= -ldl

SRCS		= main.cpp		\
		  Score.cpp		\
		  Loader.cpp		\
		  Map.cpp		\
		  ArcadeCore.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME) libraries

libraries:
	 make -C ./lib

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean clean re libraries


