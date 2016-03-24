##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:19:58 2016 Erwan Dupard
## Last update Thu Mar 24 14:50:23 2016 Erwan Dupard
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -fPIC -W -Wall -Werror -Wextra -std=c++11

LDXXFLAGS		= -I ../../deps/caca/include -L../../deps/caca/ -lcaca

NAME			= ../../lib/libarcade_caca.so

SRCS			= myCaca.cpp		\

OBJS			= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) -shared $(OBJS) $(CXXFLAGS) $(LDXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
