/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:51:05 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:35 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	is_exit(t_game *game, int x, int y)
{
	if (game->map.map_sketch[x][y] == 'E')
	{
		if (game->collected == game->to_collect)
		{
			ft_printf_styled("Congratulations!\n", 'w', 'b');
			ft_printf("You won in %d moves!\n", game->moves);
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
	if (game->map.map_sketch[y][x] == 'C')
	{
		game->map.map_sketch[y][x] = '0';
		game->collected++;
		ft_printf_styled("Found 1 pair of dirty socks!\n", 'w', 'i');
	}
}

int	can_walk(t_game *game, int new_x, int new_y)
{
	if (new_x <= 0 || new_x >= (game->map.columns))
		return (0);
	if (new_y <= 0 || new_y >= (game->map.rows))
		return (0);
	if (game->map.map_sketch[new_x][new_y] == '1')
		return (0);
	return (1);
}
void	walk(t_game *game, int to_x, int to_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + to_x;
	new_y = game->player.y + to_y;
	if (!can_walk(game, new_x, new_y))
	{
		ft_printf_styled("Can't go there :(\n", 'y', 'i');
		return ;
	}
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;
	ft_printf_styled("Moves count so far: ", 'w', 'i');
	ft_printf("%d\n", game->moves);
	is_collectable(game, new_x, new_y);
	is_exit(game, new_x, new_y);
	render_map(game);
}
