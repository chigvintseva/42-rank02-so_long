/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:15 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 04:27:09 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv);
	init_game(&game);
	load_map(&game, argv[1]);
	// if (map_valid(&game) == 0)
	// 	invalid_map_error(&game);
	// start_game(&game, argv[1]);
	// load_textures(&game);
	// render_map(&game);
	// mlx_key_hook(game.mlx_win, key_handler(&game), &game);
	// GAME LOOP
	//mlx_loop(game.mlx);


	
	return (0);
}