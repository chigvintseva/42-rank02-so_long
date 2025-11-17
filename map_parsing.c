/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:04:13 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 05:04:24 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_rows(char *file_map)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		return (-1);
	rows = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

int	read_map(t_game *game, int fd)
{
	int		i;
	char	*line;
	int		line_length;
	
	i = 0;
	while (i < game->map.rows)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
		line_length = ft_strlen(line);
		if (line_length > 0 && (line[line_length - 1] == '\n'))
		{
			line[line_length - 1] = '\0';
			line_length--;
		}
		if (line_length == 0)
			return (free(line), close(fd), 0);
		game->map.map_sketch[i] = line;
		if (i == 0)
			game->map.columns = line_length;
		i++;
	}
	game->map.map_sketch[i] = NULL;
	return (1);
}

void	load_map(t_game *game, char *file_map)
{
	int		fd;

	game->map.rows = count_map_rows(file_map);
	if (game->map.rows <= 0)
		error_exit("Map file is empty/not possible to open\n");
	game->map.map_sketch = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map_sketch)
		error_exit("Memory allocation error\n");
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		free(game->map.map_sketch);
		error_exit("Couldn't open the map file\n");
	}
	if (read_map(game, fd) == 0)
		error_exit("Mar reading error\n");
	close(fd);
}
int	map_valid(t_game *game)
{
	if (!map_rectangular(game))
		return (0);
	if (!map_walls(game))
		return (0);
	if (!map_characters(game))
		return (0);
	if (!map_elements(game))
		return (0);
	if (!map_playable(game))
		return (0);
	return (1);		
}
