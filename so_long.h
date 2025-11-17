/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:22:03 by achigvin          #+#    #+#             */
/*   Updated: 2025/11/17 00:58:12 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include "X11/keysym.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "sys/time.h"

# define W_WIDTH 80
# define W_HEIGHT 80

// player position
typedef struct s_position
{
	unsigned int	x;
	unsigned int	y;
}	t_position;

// to store the images (textures folder)
typedef struct s_image
{
	void				*img;
	char				*address;
	unsigned int		width;
	unsigned int		height;
}	t_image;

// map info
typedef struct s_map
{
	char			**map_sketch;
	unsigned int	rows;
	unsigned int	columns;
}	t_map;

// all game info (prev.structs) + playing setup n moves
typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	unsigned int	moves;
	t_map			map;
	t_position		player;
	t_image			wall;
	t_image			collect;
	t_image			exit;
	t_image			space;
}	t_game;


#endif