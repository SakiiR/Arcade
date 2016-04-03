##
## Makefile for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_lapin
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Wed Mar  9 18:21:25 2016 Erwan Dupard
## Last update Sun Apr  3 21:33:09 2016 Erwan Dupard
##

CC			= g++

RM			= rm -f

CXXFLAGS		= -fPIC -shared -W -Wall -Werror -Wextra -std=c++11

CPPFLAGS		= -I../../deps/lapin/include 	\
			-L../../deps/lapin/lib		\
			-llapin				\
			-lsfml-audio 			\
			-lsfml-graphics 		\
			-lsfml-window 			\
			-lsfml-system 			\
			-lstdc++ -ldl 			\
			-lm				\

NAME			= ../../lib/lib_arcade_lapin.so

SRCS			= myLapin.cpp		\

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
