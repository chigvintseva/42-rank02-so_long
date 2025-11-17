/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:51:05 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 12:18:33 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_exit(t_game *game, int x, int y)
{
	if (game->map.map_sketch[x][y] == 'E')
	{
		if (game->collected == game->to_collect)
		{
			ft_printf_styled("Congratulations!\n", 'w', 'b');
			ft_printf_styled("You won in %d moves!\n", 'g', 'b');
			success_game(game);
		}
		else
		{
			ft_printf_styled("Ops... You dont have enough socks...\n", 'r', 0);
			ft_printf_styled("Collect all items first!\n", 'r', 'b');
			printf("Ready for laundary basket now: only %d out of %d", game->collected, game->to_collect);
		}
	}
}

void	is_collectable(t_game *game, int x, int y)
{
	if (game->map.map_sketch == 'C')
	{
		game->map.map_sketch[y][x] = '0';
		game->collected++;
		ft_printf_styled("Found 1 pair of dirty socks!\n", 'w', 'i');
	}
}

void	can_walk(t_game *game, int x, int y)
{
	
}
void	walk(t_game *game, int to_walk_x, int to_walk_y)
{
	int	new_x;
	int	new_y;

	
}
