##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Mar  8 14:37:11 2016 Erwan Dupard
## Last update Wed Mar  9 18:34:08 2016 Erwan Dupard
##

CC		= g++

RM		= rm -f

NAME		= arcade

CXXFLAGS	+= -Wall -Werror -W -Wextra -std=c++11

LDXXFLAGS	+= -ldl

SRCS		= main.cpp		\
		  Score.cpp		\
		  Loader.cpp		\

OBJS		= $(SRCS:.cpp=.o)


all: $(NAME) libraries

libraries:
	make -C ./lib

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDXXFLAGS)

clean:
	$(RM) $(OBJS)
	make -C ./lib clean

fclean: clean
	$(RM) $(NAME)
	make -C ./lib fclean

re: fclean all
	make -C ./lib re

.PHONY: all clean clean re


