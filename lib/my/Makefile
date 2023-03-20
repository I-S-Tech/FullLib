##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC			=	$(wildcard *.c)

HEADERS		=	includes.h				\
				h_headers.h				\
				h_lib.h					\
				h_lists.h				\
				h_macros.h				\
				h_types.h				\

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

DEBUG_FLAGS	=	-Wall -Wextra -ggdb

$(NAME):	all

all:		compile

compile:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(HEADERS) ../../includes/lib/
	cp $(NAME) ../

debug:
	gcc -c $(SRC) $(DEBUG_FLAGS)
	ar rc $(NAME) $(OBJ)
	cp $(HEADERS) ../../includes/lib/
	cp $(NAME) ../

clean:
	rm -rf *~
	rm -rf \#*\#
	rm -rf $(OBJ)

fclean:		clean
	rm -rf ../../includes/lib/*
	rm -rf ../$(NAME)
	rm -rf $(NAME)

re:			fclean	compile

re-debug:	fclean debug
