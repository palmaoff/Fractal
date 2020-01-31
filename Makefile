NAME = fractol

SRC =   main.c \
		img.c \
		fractol.c \
		key.c \
		zoom.c \
		peaces.c \
		input.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft
LIB_INK = -I ./libft
LIBFT =	libft/libft.a

MLX = ./minilibx_macos
MLX_LIB	= $(addprefix $(MLX),/libmlx.a)
MLX_INK	= -I ./minilibx_macos

MLX_LNK = -framework OpenGL -framework AppKit

SRCDIR	= ./src/
INKDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME) 

$(NAME): $(MLX_LIB) obj $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT) -o $(NAME) $(MLX_LNK)
		@echo "\033[32m- fractol compiled\033[0m"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c ./includes/fractol.h
		$(CC) $(FLAGS) $(MLX_INK) $(LIB_INK) -c -I $(INKDIR) $< -o $@
		
$(MLX_LIB): ./minilibx_macos/
	@make -C $(MLX)
	@echo "\033[32m- libmlx compiled\033[0m"

$(LIBFT): ./libft
	@make -C $(LIB)
	@echo "\033[32m- libft compiled\033[0m"

clean:
		@rm -f $(OBJ)
		@make -C $(LIB) clean
		@make -C $(MLX) clean
		@echo "\033[31m- fractol object files removed\033[0m"

fclean: clean
		@rm -f $(NAME)
		@make -C $(MLX) clean
		@echo "\033[31m- libmlx.a removed\033[0m"
		@make -C $(LIB) fclean
		@echo "\033[31m- libft.a removed\033[0m"

re: fclean all

.PHONY : all, re, clean, fclean
