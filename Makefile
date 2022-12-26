NAME = bin/push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

MAKEFLAGS += --no-print-directory

SHELL=/bin/bash
UNAME = $(shell uname -s)


LIBFTEXT = libftext/libftext.a
LIBFTEXT_HEADER_DIR = libftext/include/


SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
HEADER_DIR = inc/
LIBFTEXT_DIR = libftext/


SRC = \
main.c \



H_FILES = \
push_swap.h \


OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

HEADER = $(addprefix $(HEADER_DIR), $(H_FILES))


all: $(NAME)


$(NAME): $(LIBFTEXT) $(OBJ)
	@if [ ! -d "$(OBJ_DIR)" ] || [ ! -d "$(BIN_DIR)" ]; then \
		make gen_dir; fi
	@$(CC) $(OBJ) $(LIBFTEXT) -o $@
	@echo "$(NAME) DONE"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@if [ ! -d "$(OBJ_DIR)" ] || [ ! -d "$(BIN_DIR)" ]; then \
		make gen_dir; fi
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIBFTEXT_HEADER_DIR) -c $< -o $@


$(LIBFTEXT):
	@make -C $(LIBFTEXT_DIR)


gen_dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@echo "'$(BIN_DIR)' and $(OBJ_DIR) DONE"

clean:
	@make clean -C $(LIBFTEXT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "'$(OBJ_DIR)' and .o REMOVE"

fclean: clean
	@make fclean -C $(LIBFTEXT_DIR)
	@rm -rf $(BIN_DIR)
	@echo "'$(BIN_DIR)' and pipex REMOVE"

re: fclean all

.PHONY: all clean fclean re gen_dir
