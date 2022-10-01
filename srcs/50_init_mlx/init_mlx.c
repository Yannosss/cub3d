/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:15 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:16 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error_exit(data, "Error: Can't init mlx");
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3D");
	if (data->window == NULL)
		ft_error_exit(data, "Error: MLX can't create window");
	data->img.img_pt = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->img.img_pt == NULL)
		ft_error_exit(data, "Error: MLX can't create image");
	data->img.addr = mlx_get_data_addr(data->img.img_pt, &(data->img.bpp),
			&(data->img.line_len), &(data->img.endian));
	if (data->img.addr == NULL)
		ft_error_exit(data, "Error: MLX error");
	data->img.width = WINDOW_WIDTH;
	data->img.height = WINDOW_HEIGHT;
}
