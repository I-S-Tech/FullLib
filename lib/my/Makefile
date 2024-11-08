##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC_DIR			=	./src/
HDR_DIR			=	./hdr/
OBJ_DIR			=	./obj/

SRC				=	$(shell find $(SRC_DIR) -type f -name '*.c')
HDR				=	$(shell find $(HDR_DIR) -type f -name '*.h')
OBJ				=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
BIN				=	libmy.a

CC				=	gcc

CFLAGS			=	-D_GNU_SOURCE -I$(HDR_DIR)

DEBUG_FLAGS		=	-Wall -Wextra -Werror -DDEBUG -Og -g3
RELEASE_FLAGS	=	-O3 -g0

.PHONY:	all
all:	$(BIN)

.PHONY: debug
debug:
	@echo "Building for debug"
	@make all --no-print-directory CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)"

.PHONY:	release
release:
	@echo "Building for release"
	@make all --no-print-directory CFLAGS="$(CFLAGS) $(RELEASE_FLAGS)"

$(BIN):	$(OBJ)
	@echo "[+] Compiling $(BIN)"
	ar rc $(BIN) $(OBJ)
	@cp $(HDR) ../../includes/lib/
	@cp $(BIN) ../

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@echo ">> Compiling C object $@"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

.PHONY:	dev
dev:
	@echo "Starting dev session"
	@echo "$(SRC) $(HDR)" | tr ' ' '\n' | entr bash -c "clear && make --no-print-directory debug"
.PHONY:	clean
clean:
	@echo "Removing compiled object directory"
	@rm -rf $(OBJ_DIR)
	@echo "Removing traces"
	@rm -f vgcore*
	@rm -f *.swp
	@rm -f *~

.PHONY:	fclean
fclean:	clean
	@echo "Removing executable and packed file"
	@rm -f $(PACK_FILE)
	@rm -f $(BIN)
	@rm -f ../$(BIN)

.PHONY:	re
re:	fclean	$(BIN)

.PHONY:	re-debug
re-debug:	fclean	debug
