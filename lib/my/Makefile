##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC			=	$(wildcard *.c)

HEADERS		=	*.h

OBJ			=	$(SRC:.c=.o)

NAME		=	libmy.a

FLAGS		=	-Werror

DEBUG_FLAGS	=	-Wall -Wextra -g3

CFLAGS		=	$(FLAGS)

CC			=	gcc

$(NAME):		all

all:
	@printf "\033[32m[LIB] Starting compilation !\033[0m\n"
	@make compile --no-print-directory
	@printf "\033[32m[LIB] Compilation successfull !\033[0m\n"

%.o:			%.c
	@printf "\033[2m[LIB] Compiling $<\033[0m\n"
	@$(CC) $(CPPFLAGS) -c $(CFLAGS) $< -o $@

compile:		$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(HEADERS) ../../includes/lib/
	@cp $(NAME) ../

debug:
	@printf "\033[92m[LIB] Starting debug compilation !\033[0m\n"
	@make compile CFLAGS="$(DEBUG_FLAGS)" --no-print-directory
	@printf "\033[92m[LIB] Debug compilation duccessfull !\033[0m\n"

clean:
	@printf "\033[31m[LIB] Starting cleanning !\033[0m\n"
	@rm -f *.swp
	@rm -f $(OBJ)
	@printf "\033[31m[LIB] Cleanning success !\033[0m\n"

fclean:		clean
	@printf "\033[91m[LIB] Starting purge !\033[0m\n"
	@rm -f ../../includes/lib/*
	@rm -f ../$(NAME)
	@rm -f $(NAME)
	@printf "\033[91m[LIB] Purge success !\033[0m\n"

re:			fclean	compile

re-debug:	fclean	debug
