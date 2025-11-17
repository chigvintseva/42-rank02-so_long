/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:22:03 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 17:34:35 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries
# include "libft/libft.h"
# include "mlx.h"
# include "X11/keysym.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "sys/time.h"
# include <stdio.h>
# include <errno.h>

// images
# define EXIT_IMG "./textures/exit.xpm"
# define PLAYER_IMG "./textures/player.xpm"
# define COLLECT_IMG "./textures/collect.xpm"
# define WALL_IMG "./textures/wall.xpm"
# define FLOOR_IMG "./textures/floor.xpm"

# define TILE 64

// keys for mlx_hook registration
# define KEYBOARD_KEY_PRESSED 2
# define WIN_CROSS_PRESSED 17

//keys (events) mask for hooks registration
// standard keypress for minilibx, OS->X11->MLX
# define KEYBOARD_MASK (1L << 0)
# define WIN_CROSS_MASK 0

// keys that can be pressed n require reaction
# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

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
	void		*mlx;
	void		*mlx_win;
	int			moves;
	int			to_collect;
	int			collected;
	t_map		map;
	t_position	player;
	t_image		wall;
	t_image		collect;
	t_image		exit;
	t_image		floor;
	t_image		player_img;
}	t_game;

// exit rules
void	error_exit(char *message);
void	error_exit_game(t_game *game, char *message);
void	success_game(t_game *game);

// user input.c
void	check_input(int argc, char **argv);
void	init_game(t_game *game);

// validity checks
int		map_rectangular(t_game *game);
int		map_walls(t_game *game);
int		map_characters(t_game *game);
int		map_elements(t_game *game);
int		map_playable(t_game *game);

//validity checks helpers 
int		check_top_bottom_walls(t_game *game);
int		check_side_walls(t_game *game);
int		is_valid_char(char c);

//elements counting 
void	init_counts(t_counts *counts);
void	process_char(t_game *game, t_counts *counts, int i, int j);
void	count_elements(t_game *game, t_counts *counts);
int		count_collectables(t_game *game);

// fill the map from the file input data (when valid)
char	**create_visited_map(t_game *game);
void	free_visited_map(char **visited, int rows);
void	flood_fill(t_game *game, char **visited, int y, int x);
int		check_all_reachable(t_game *game, char **visited);

// map parsing.c
int		count_map_rows(char *file_map);
int		read_map(t_game *game, int fd);
void	load_map(t_game *game, char *file_map);
int		map_valid(t_game *game);

// start game
void	start_game(t_game *game);
void	load_image(t_game *game, t_image *img, char *path);
void	load_textures(t_game *game);

// render map.c
void	place_img_in_game(t_game *game, void *img, int x, int y);
void	render_game_part(t_game *game, char part, int x, int y);
void	render_map(t_game *game);

//walking!
void	is_exit(t_game *game, int x, int y);
void	is_collectable(t_game *game, int x, int y);
int		can_walk(t_game *game, int new_x, int new_y);
void	walk(t_game *game, int to_x, int to_y);

// key_pressed.c
int		close_window(t_game *game);
int		key_pressed( int key_pressed, t_game *game);
void	cross_hook(t_game *game);
void	keyboard_hook(t_game *game);

#endif