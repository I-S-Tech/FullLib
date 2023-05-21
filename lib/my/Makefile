##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

LIB_SRC		=	$(wildcard *.c my_lists/*.c my_debug/*.c my_printf/*.c)

LIBNAME		=	libmy.a

LIB_HEADERS	=	*.h

FLAGS		=	-Werror

DEBUG_FLAGS	=	-Wall -Wextra -g3

LIB_OBJ		=	$(LIB_SRC:.c=.o)

CC			=	gcc

CFLAGS	   ?=	$(FLAGS)

all:
	@printf "\033[32m[LIB] Starting compilation !\033[0m\n"
	@make compile --no-print-directory
	@printf "\033[32m[LIB] Compilation successfull !\033[0m\n"

$(LIBNAME):			all

%.o:				%.c
	@printf "\033[2m[LIB] Compiling $< => $@\033[0m\n"
	@$(CC) -c $(CFLAGS) $< -o $@

compile:		$(LIB_OBJ)
	@ar rc $(LIBNAME) $(LIB_OBJ)
	@cp $(LIB_HEADERS) ../../includes/lib/
	@cp $(LIBNAME) ../

debug:
	@printf "\033[92m[LIB] Starting debug compilation !\033[0m\n"
	@make compile CFLAGS="$(FLAGS) $(DEBUG_FLAGS)" --no-print-directory
	@printf "\033[92m[LIB] Debug compilation duccessfull !\033[0m\n"

clean:
	@printf "\033[31m[LIB] Starting cleanning !\033[0m\n"
	@rm -f *.swp
	@rm -f $(LIB_OBJ)
	@printf "\033[31m[LIB] Cleanning success !\033[0m\n"

fclean:		clean
	@printf "\033[91m[LIB] Starting purge !\033[0m\n"
	@rm -f ../../includes/lib/*
	@rm -f ../$(LIBNAME)
	@rm -f $(LIBNAME)
	@printf "\033[91m[LIB] Purge success !\033[0m\n"

re:					fclean	compile

re-debug:			fclean	debug
