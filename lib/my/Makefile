##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC			=	my_box.c 				\
				my_colors.c 			\
				my_debug.c 				\
				my_getnbr.c				\
				my_math.c				\
				my_memory.c				\
				my_putchar.c			\
				my_putnbr_base.c		\
				my_putnbr.c				\
				my_putstr.c				\
				my_showstr.c			\
				my_str_are_in.c			\
				my_str_checks.c			\
				my_str_count.c			\
				my_str_find.c			\
				my_str_join.c			\
				my_strcat.c				\
				my_strcmp.c				\
				my_strcpy.c				\
				my_strdup.c				\
				my_strlen.c				\
				my_lists_alpha.c 		\
				my_lists_bravo.c 		\

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

compile:
	gcc -c $(SRC)
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
