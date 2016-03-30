##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_snake
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:27:24 2016 Erwan Dupard
## Last update Wed Mar 30 17:47:13 2016 Barthelemy Gouby
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -fPIC -shared -W -Wall -Werror -Wextra -std=c++11 -rdynamic

LDXXFLAGS		= 

NAME			= ../../games/lib_arcade_snake.so

SRCS			= Snake.cpp		\
			  SnakePlayer.cpp	\
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
