/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_cnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:42:01 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 12:00:45 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_counts(t_counts *counts)
{
	counts->player = 0;
	counts->exit = 0;
	counts->collectible = 0;
}

void	process_char(t_game *game, t_counts *counts, int i, int j)
{
	char	c;

	c = game->map.map_sketch[i][j];
	if (c == 'P')
	{
		counts->player++;
		game->player.x = j;
		game->player.y = i;
	}
	else if (c == 'E')
		counts->exit++;
	else if (c == 'C')
		counts->collectible++;
}

void	count_elements(t_game *game, t_counts *counts)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			process_char(game, counts, i, j);
			j++;
		}
		i++;
	}
}

int	count_collectables(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (i < (game->map.rows))
	{
		j = 0;
		while (j < (game->map.columns))
		{
			if (game->map.map_sketch[i][j] == 'C')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}
