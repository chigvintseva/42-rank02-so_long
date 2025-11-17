/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:21:52 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 18:29:18 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	cleanup_images(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->player_img.img)
		mlx_destroy_image(game->mlx, game->player_img.img);
	if (game->collect.img)
		mlx_destroy_image(game->mlx, game->collect.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
}

void	error_exit_game(t_game *game, char *message)
{
	int	i;

	if (game->map.map_sketch)
	{
		i = 0;
		while (i < game->map.rows)
		{
			free(game->map.map_sketch[i]);
			i++;
		}
		free(game->map.map_sketch);
	}
	cleanup_images(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	error_exit(message);
}

void	success_game(t_game *game)
{
	int	i;

	if (game->map.map_sketch)
	{
		i = 0;
		while (i < game->map.rows)
		{
			free(game->map.map_sketch[i]);
			i++;
		}
		free(game->map.map_sketch);
	}
	cleanup_images(game);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_printf_styled("Game is finised, thx for playing :)\n", 'g', 'b');
	exit(EXIT_SUCCESS);
}
