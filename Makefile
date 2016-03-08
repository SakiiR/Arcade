##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Mar  8 14:37:11 2016 Erwan Dupard
## Last update Tue Mar  8 14:40:46 2016 Erwan Dupard
##

CC		= g++

RM		= rm -f

NAME		= arcade

CXXFLAGS	+= -Wall -Werror -W -Wextra

LDXXFLAGS	+= 

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CXXFLAGS) $(LDXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean clean re


