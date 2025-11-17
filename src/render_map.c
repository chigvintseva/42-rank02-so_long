/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:36 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 17:34:39 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	place_img_in_game(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * TILE, y * TILE);
}

void	render_game_part(t_game *game, char part, int x, int y)
{
	place_img_in_game(game, game->floor.img, x, y);
	if (part == '1')
		place_img_in_game(game, game->wall.img, x, y);
	else if (part == 'E')
		place_img_in_game(game, game->exit.img, x, y);
	else if (part == 'C')
		place_img_in_game(game, game->collect.img, x, y);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (game->map.rows))
	{
		j = 0;
		while (j < (game->map.columns))
		{
			render_game_part(game, game->map.map_sketch[i][j], j, i);
			j++;
		}
		i++;
	}
	place_img_in_game(game, game->player_img.img, game->player.x, game->player.y);
}
