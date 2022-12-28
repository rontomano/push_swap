NAME := push_swap

MAKEFLAGS += --no-print-directory

MK_DIR = mkdir -p $(@D)

SHELL := /bin/bash
UNAME := $(shell uname -s)


LIBFT := libft/libft.a

SRC_DIR := src/
BUILD_DIR := .build/

SRC := \
main.c \


SRC := $(SRC:%=$(SRC_DIR)%)


INC := \
inc/ \
libft/inc/


OBJS := $(SRC:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)

DEPS := $(OBJS:.o=.d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

CPPFLAGS := $(addprefix -I, $(INC)) -MMD -MP

RM = rm -rf

RED_COL :=$(shell tput setaf 1)
GREEN_COL :=$(shell tput setaf 2)
RESET_COL :=$(shell tput sgr0)

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LIBFT) $(CFLAGS) $(OBJS) -o $(NAME)
	$(info $(GREEN_COL)CREATED $(NAME)$(RESET_COL))

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	$(MK_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(dir $(LIBFT))

-include $(DEPS)

clean:
	make clean -C $(dir $(LIBFT))
	$(RM) $(BUILD_DIR)
	$(info $(RED_COL)DELETED $(BUILD_DIR)$(RESET_COL))

fclean: clean
	make fclean -C $(dir $(LIBFT))
	$(RM) $(NAME)
	$(info $(RED_COL)DELETED $(NAME)$(RESET_COL))

re: fclean all

print-%:
	$(info '$*'='$($*)')

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"


.PHONY: all clean fclean re gen_dir

.SILENT:
