CC = gcc

NAME = libftext.a


CFLAGS = -Wall -Wextra -Werror -g3 -c

MAKEFLAGS += --no-print-directory

LIBFT = libft/

SRC_DIR = src/

OBJ_DIR = obj/

HEADER_DIR = include/

FILES = \
ft_printf \
ft_printf_utils \
ft_put_ptr \
ft_putnbr_hex \
ft_putnbr_int \
ft_putnbr_uns \
get_next_line \
get_next_line_utils \

H_FILES = \
ft_printf \
get_next_line \
libft \


SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

HEADER = $(addprefix $(HEADER_DIR), $(addsuffix .h, $(H_FILES)))


all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@mv $(LIBFT)libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)
	@echo "'$(NAME)' DONE"

$(OBJ): $(HEADER) $(SRC)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIBFT) $(SRC)
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir $(OBJ_DIR); fi
	@mv $(addsuffix .o, $(FILES)) $(OBJ_DIR)

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
