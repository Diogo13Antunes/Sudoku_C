# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 10:17:05 by dcandeia          #+#    #+#              #
#    Updated: 2022/05/03 14:33:59 by dcandeia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sudoku

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx
LMLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

$(VERBOSE).SILENT:

HEADER = sudoku.h

INC = -I ./includes

SRC_PATH = ./sources

OBJ_PATH = ./objects

SRC_NAME = 	print_information.c					\
			init_variables.c					\
			get_next_line.c						\
			mouse_keyboard.c					\
			board.c								\
			game.c								\
			game_utils.c						\
			main.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
	clear;
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) $(INC) $(LMLX_FLAGS) -o $(NAME) -L ./minilibx_opengl_20191021
	echo "\x1b[36m[SUDOKU COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

norminette:
	clear
	echo "\x1b[31m[NORMINETTE]\x1b[0m"
	norminette | egrep -B1 'Error|Warning' | sed ''/Error/s//$(printf "\033[31m\033[4mError\033[0m")/'' | sed ''/Warning/s//$(printf "\033[33m\033[4mWarning\033[0m")/''

clean:
	rm -rf $(OBJ_PATH)
	echo "\033[33mall $(NAME).o files are removed\033[0m"

fclean: clean
	rm -f $(NAME)
	echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re force norminette
