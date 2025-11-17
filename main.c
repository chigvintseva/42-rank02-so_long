/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:15 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 00:07:07 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	exit_with_error()
// {
// 	write(1, "Error\n", 6);
// 	exit_error();
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
		+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	//windows creation
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "My attempt");
	
		
	// GAME LOOP
	mlx_loop(mlx);

	
	//cleaning up
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	return (0);
}