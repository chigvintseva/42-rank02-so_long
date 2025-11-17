/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:22:03 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 04:39:59 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include "X11/keysym.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "sys/time.h"
# include <stdio.h>
# include <errno.h>

# define W_WIDTH 32
# define W_HEIGHT 32

// player position
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

// to store the images (textures folder)
typedef struct s_image
{
	void	*img;
	char	*address;
	int		width;
	int		height;
}	t_image;

// map info
typedef struct s_map
{
	char	**map_sketch;
	int		rows;
	int		columns;
}	t_map;

typedef struct s_counts
{
	int	player;
	int	exit;
	int	collectible;
}	t_counts;

// all game info (prev.structs) + playing setup n moves
typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	int				moves;
	t_map			map;
	t_position		player;
	t_image			wall;
	t_image			collect;
	t_image			exit;
	t_image			space;
}	t_game;

// exit rules
void	error_exit(char *message);
void	error_exit_game(t_game *game, char *message);
void	success_game(t_game *game);

// user input.c
void	check_input(int argc, char **argv);
void	init_game(t_game *game);

// map parsing.c
int		count_map_rows(char *file_map);
int		read_map(t_game *game, int fd);
void	load_map(t_game *game, char *file_map);
int		map_valid(t_game *game);

// validity checks
int		map_rectangular(t_game *game);
int		map_walls(t_game *game);
int		map_characters(t_game *game);
int		map_elements(t_game *game);
int		map_playable(t_game *game);

//validity checks helpers 

#endif