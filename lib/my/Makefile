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

FLAGS		=	-Werror

DEBUG_FLAGS	=	-Wall -Wextra -g3

CFLAGS		=	$(FLAGS)

CC			=	gcc

$(NAME):		all

all:
	@echo "\033[32m[LIB] Starting compilation !\033[0m"
	@make compile MAKELEVEL=0
	@echo "\033[32m[LIB] Compilation successfull !\033[0m"

%.o:			%.c
	@echo "\033[2m[LIB] Compiling $<\033[0m"
	@$(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@

compile:		$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(HEADERS) ../../includes/lib/
	@cp $(NAME) ../

debug:
	@echo "\033[92m[LIB] Starting debug compilation !\033[0m"
	@make compile CFLAGS="$(DEBUG_FLAGS)" MAKELEVEL=0
	@echo "\033[92m[LIB] Debug compilation duccessfull !\033[0m"

clean:
	@echo "\033[31m[LIB] Starting cleanning !\033[0m"
	@rm -f *.swp
	@rm -f $(OBJ)
	@echo "\033[31m[LIB] Cleanning success !\033[0m"

fclean:		clean
	@echo "\033[91m[LIB] Starting purge !\033[0m"
	@rm -f ../../includes/lib/*
	@rm -f ../$(NAME)
	@rm -f $(NAME)
	@echo "\033[91m[LIB] Purge success !\033[0m"

re:			fclean	compile

re-debug:	fclean	debug
