/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:15 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 12:03:37 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv);
	init_game(&game);
	load_map(&game, argv[1]);
	if (!map_valid(&game))
	 	error_exit_game(&game, "Invalip map!\n");
	else 
		ft_printf_styled("Valid Map! Let's Go!\n", 'g', 'i');
	start_game(&game);
	load_textures(&game);
	// render_map(&game);
	// mlx_key_hook(game.mlx_win, key_handler(&game), &game);
	// GAME LOOP
	//mlx_loop(game.mlx);


	
	return (0);
}