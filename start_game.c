/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:03:24 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 09:18:19 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	int	win_width;
	int	win_height;

	game->mlx = mlx_init();
	if (!(game->mlx))
		error_exit_game(game, "MLX initialisation failed\n");
	win_height = game->map.rows * TILE;
	win_width = game->map.columns * TILE;
	game->mlx_win = mlx_new_window(game->mlx, win_width, win_height, 
	"so_long");
	if (!(game->mlx_win))
		error_exit_game(game, "MLX Window creation failed\n");
}

void	load_image(t_game *game, t_image *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	if (!(img->img))
		error_exit_game(game, "Texture loading failed\n");
}

void	load_textures(t_game *game)
{
	load_image(game, &game->wall, WALL_IMG);
	load_image(game, &game->floor, FLOOR_IMG);
	load_image(game, &game->player_img, PLAYER_IMG);
	load_image(game, &game->collect, COLLECT_IMG);
	load_image(game, &game->exit, EXIT_IMG);
}
