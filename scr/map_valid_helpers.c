/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 04:41:03 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 13:38:48 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_top_bottom_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.map_sketch[0][i] != '1')
			return (0);
		if (game->map.map_sketch[game->map.rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_side_walls(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->map.rows)
	{
		if (game->map.map_sketch[j][0] != '1')
			return (0);
		if (game->map.map_sketch[j][game->map.columns - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_valid_char(char c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'C')
		return (1);
	return (0);
}
