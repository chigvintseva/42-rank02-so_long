/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:03:11 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 09:01:24 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char **argv)
{
	size_t	len;
	int		fd;

	if (argc != 2)
		error_exit("Invalid input.\nValid example: ./so_long maps/map.ber\n");
	len = ft_strlen(argv[1]);
	if (len < 5)
		error_exit("Invalid input.\nValid example: ./so_long maps/map.ber\n");
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
		error_exit("Invalid filename or filetype.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nNot able to open map file\n");
		exit(EXIT_FAILURE);
	}
	close(fd);	
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->moves = 0;
	game->collected = 0;
	game->to_collect = 0;
	game->map.map_sketch = NULL;
	game->map.rows = 0;
	game->map.columns = 0;
	game->player.x = 0;
	game->player.y = 0;
}
