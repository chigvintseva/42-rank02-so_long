/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:42:53 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 04:42:57 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_visited_map(t_game *game)
{
	char	**visited;
	int		i;
	int		j;

	visited = malloc(sizeof(char *) * game->map.rows);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		visited[i] = malloc(sizeof(char) * game->map.columns);
		if (!visited[i])
			return (free_visited_map(visited, i), NULL);
		j = 0;
		while (j < game->map.columns)
		{
			visited[i][j] = '0';
			j++;
		}
		i++;
	}
	return (visited);
}

void	free_visited_map(char **visited, int rows)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	flood_fill(t_game *game, char **visited, int y, int x)
{
	if (y < 0 || y >= game->map.rows)
		return ;
	if (x < 0 || x >= game->map.columns)
		return ;
	if (game->map.map_sketch[y][x] == '1')
		return ;
	if (visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	flood_fill(game, visited, y - 1, x);
	flood_fill(game, visited, y + 1, x);
	flood_fill(game, visited, y, x - 1);
	flood_fill(game, visited, y, x + 1);
}

int	check_all_reachable(t_game *game, char **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (game->map.map_sketch[i][j] == 'C' && visited[i][j] != '1')
				return (0);
			if (game->map.map_sketch[i][j] == 'E' && visited[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
