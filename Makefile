# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 16:24:27 by achigvin          #+#    #+#              #
#    Updated: 2025/11/17 04:53:48 by achigvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -O2 -g
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

#---------- maps and textures??--------


# ---------

SRC = main.c \
		user_input.c \
		map_parsing.c \
		exit_game.c \
		map_valid_check.c \
		map_valid_helpers.c \
		map_fill.c \
		map_elements_cnt.c \
		
		
	

# ------------creating objects---
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# -------- name rule --------
all: $(LIBFT) $(NAME)

# --------- main compilation-----------
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

# ------ libft compilation, -C flag is for "change directory to the subdirectory libft"
$(LIBFT):
	$(MAKE) -C libft

# --------------objects compilation ---
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


# --------- clean fclean re rules-----------
clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	rm -rf $(OBJ_DIR)

re: fclean all

# -------------------
.PHONY: all clean fclean re
