/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:16 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:18 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_red_pixel_on_2d_map(t_data *data, double x, double y)
{
	ft_img_pixel_put(data, BLOCKSIZE_2D * x, BLOCKSIZE_2D * y, MLX_COLOR_RED);
}

void	ft_print_orange_pixel_on_2d_map(t_data *data, double x, double y)
{
	ft_img_pixel_put(data, BLOCKSIZE_2D * x, BLOCKSIZE_2D * y,
		MLX_COLOR_ORANGE);
}

// print 2D map without checking size
void	ft_print_map_in_2d(t_data *data)
{
	int	square_size;
	int	i;
	int	j;

	square_size = BLOCKSIZE_2D;
	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[i][j] == '1')
				ft_draw_square(data, i * square_size, j * square_size,
					square_size);
			i++;
		}
		j++;
	}
	ft_print_red_pixel_on_2d_map(data, data->player.x, data->player.y);
}
