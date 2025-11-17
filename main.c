/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:15 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 03:24:53 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	error_exit(t_game *game, char *message)
{
	int	i;
	
	if (game)
	{
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
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	success_game(t_game *game)
{
	int	i;

	if (game)
	{
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
	}
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_putstr_fd("Success! You finished the game!\n", 1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv, &game);
	// load_map(&game, argv[1]);
	// if (map_valid(&game) == 0)
	// 	invalid_map_error(&game);
	// start_game(&game, argv[1]);
	// load_textures(&game);
	// render_map(&game);
	// mlx_key_hook(game.mlx_win, key_handler(&game), &game);
	// GAME LOOP
	mlx_loop(game.mlx);
	return (0);
}