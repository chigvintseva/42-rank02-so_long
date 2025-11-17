/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:29:31 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 18:04:59 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (game->map.rows < 3 || game->map.columns < 3)
		return (0);
	i = 0;
	while (i < game->map.rows)
	{
		len = ft_strlen(game->map.map_sketch[i]);
		if (len != game->map.columns)
			return (0);
		i++;
	}
	return (1);
}
int	map_walls(t_game *game)
{
	if (!check_top_bottom_walls(game))
		return (0);
	if (!check_side_walls(game))
		return (0);
	return (1);
}

int	map_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (!is_valid_char(game->map.map_sketch[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_elements(t_game *game)
{
	t_counts	counts;

	init_counts(&counts);
	count_elements(game, &counts);
	if (counts.player != 1)
		return (0);
	if (counts.exit != 1)
		return (0);
	if (counts.collectible < 1)
		return (0);
	return (1);
}

int	map_playable(t_game *game)
{
	char	**visited;
	int		result;

	visited = create_visited_map(game);
	if (!visited)
		return (0);
	flood_fill(game, visited, game->player.y, game->player.x);
	result = check_all_reachable(game, visited);
	free_visited_map(visited, game->map.rows);
	return (result);
}
