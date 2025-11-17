/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:26 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 13:04:17 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_pressed(t_game *game, int key_pressed)
{
	int	to_x;
	int	to_y;

	to_x = 0;
	to_y = 0;
	if (key_pressed == ESC)
		close_window(game);
	else if (key_pressed == W_KEY || key_pressed == UP)
		to_y = -1;
	else if (key_pressed == S_KEY || key_pressed == DOWN)
		to_y = 1;
	else if (key_pressed == A_KEY || key_pressed == LEFT)
		to_x = -1;
	else if (key_pressed == D_KEY || key_pressed == RIGHT)
		to_x = 1;
	else
		return ;
	walk(game, to_x, to_y);
}

