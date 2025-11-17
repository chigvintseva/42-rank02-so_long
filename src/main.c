/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:15 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 17:34:39 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	game.to_collect = count_collectables(&game);
	start_game(&game);
	load_textures(&game);
	render_map(&game);
	keyboard_hook(&game);
	cross_hook(&game);
	mlx_loop(game.mlx);
	return (0);
}
