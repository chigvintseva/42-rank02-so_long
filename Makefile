# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/16 16:24:27 by achigvin          #+#    #+#              #
#    Updated: 2025/11/17 14:05:50 by achigvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long



LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a



CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -I$(LIBFT_DIR) -O2 -g
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz



# ---------
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/exit_game.c \
		$(SRC_DIR)/key_pressed.c \
		$(SRC_DIR)/map_elements_cnt.c \
		$(SRC_DIR)/map_fill.c \
		$(SRC_DIR)/map_parsing.c \
		$(SRC_DIR)/map_valid_check.c \
		$(SRC_DIR)/map_valid_helpers.c \
		$(SRC_DIR)/render_map.c \
		$(SRC_DIR)/start_game.c \
		$(SRC_DIR)/user_input.c \
		$(SRC_DIR)/walking.c
	

# ------------creating objects---
OBJ_DIR = $(SRC_DIR)/obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)



# -------- name rule --------
all: $(LIBFT) $(NAME)



# --------- main compilation-----------
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)



# ------ libft compilation, -C flag is for "change directory to the subdirectory libft"
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)



# --------------objects compilation ---
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@




# --------- clean fclean re rules-----------
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)

re: fclean all



# -------------------
.PHONY: all clean fclean re
