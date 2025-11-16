/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:57:15 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/16 22:50:38 by achigvin         ###   ########.fr       */
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
	
	//new img
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, 
		&img.bits_per_pixel, 
		&img.line_length, 
		&img.endian);
	
	//draw dots in colours
	my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 20, 20, 0x000000FF);
	my_mlx_pixel_put(&img, 30, 30, 0x0000FF00);
	
	// show the image inside the windows
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		
	// loop till ctrl c
	mlx_loop(mlx);
	//cleaning up
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	return (0);
}