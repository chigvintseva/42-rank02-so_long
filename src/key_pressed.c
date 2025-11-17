/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:26 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:13 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_game *game)
{
	ft_printf_styled("Window was closed.\n", 'r', 0);
	success_game(game);
	return (0);
}

int	key_pressed(int key_pressed, t_game *game)
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
		return (0);
	walk(game, to_x, to_y);
	return (0);
}

void	keyboard_hook(t_game *game)
{
	mlx_hook(game->mlx_win, KEYBOARD_KEY_PRESSED, KEYBOARD_MASK, key_pressed, game);
}

void	cross_hook(t_game *game)
{
	mlx_hook(game->mlx_win, WIN_CROSS_PRESSED, WIN_CROSS_MASK, close_window, game);
}
