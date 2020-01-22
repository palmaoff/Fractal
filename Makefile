NAME = fractal

SRC =   main.c \
		img.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft/
LIB_INK = -I ./libft
LIBFT =	libft/libft.a

MLX = ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INK	= -I ./minilibx_macos

MLX_LNK = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCDIR	= ./src/
INKDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)

$(NAME): obj $(MLX_LIB) $(LIBFT) $(OBJ) ./libft/*
		@$(CC) $(FLAGS) $(OBJ) $(MLX_LNK) -o $(NAME) $(LIBFT)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		$(CC) $(FLAGS) $(MLX_INK) -I $(INKDIR) $(LIB_INK) -o $@ -c $< 
		
$(MLX_LIB):
	@make -C $(MLX)

$(LIBFT):
	@make -C $(LIB)

clean:
		@rm -f $(OBJ)
		@make -C $(LIB) clean
		@make -C $(MLX) clean

fclean: clean
		@rm -f $(NAME)
		@make -C $(LIB) fclean

re: fclean all

.PHONY : all, re, clean, fclean
