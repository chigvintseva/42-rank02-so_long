/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:05:12 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 02:51:41 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key, t_game *game)
{
	if (key == 27)
		close_game(game);
	else if (key == 'W' || key == 'w')
		move_up(game);
	else if (key == 'S' || key == 's')
		move_down(game);
	else if (key == 'A' || key == 'a')
		move_left(game);
	else if (key == 'D' || key == 'd')
		move_right(game);
	return (0);
}