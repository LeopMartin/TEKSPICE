##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-tekspice-thibault.avon
## File description:
## Makefile
##

SRC		=		main.cpp			\
				src/AComponent.cpp	\
				src/parser.cpp		\
				src/shell.cpp		\
				src/input.cpp		\
				src/output.cpp		\
				src/chipset/4071.cpp	\
				src/chipset/gate.cpp

NAME	=		nanotekspice

GGFLAGS	=		-Wall -Wextra -Werror -std=c++20

all		:
				g++ $(SRC) $(GGFLAGS) -o $(NAME) -g3 -I inc/

clean	:
				rm -f *~
				rm -f *.o

fclean	:		clean
				rm -f $(NAME)

re		:		fclean all
