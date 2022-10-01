/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:31 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:32 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_mlx(t_data *data)
{
	if (data->mlx)
	{
		if (data->window)
		{
			if (data->img.img_pt)
			{
				mlx_destroy_image(data->mlx, data->img.img_pt);
				data->img.img_pt = NULL;
				data->img.addr = NULL;
			}
			mlx_destroy_window(data->mlx, data->window);
			data->window = NULL;
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	ft_free_texture_image(t_data *data)
{
	if (data->textures.north_img.img_pt)
	{
		mlx_destroy_image(data->mlx, data->textures.north_img.img_pt);
	}
	if (data->textures.south_img.img_pt)
	{
		mlx_destroy_image(data->mlx, data->textures.south_img.img_pt);
	}
	if (data->textures.east_img.img_pt)
	{
		mlx_destroy_image(data->mlx, data->textures.east_img.img_pt);
	}
	if (data->textures.west_img.img_pt)
	{
		mlx_destroy_image(data->mlx, data->textures.west_img.img_pt);
	}
}

void	ft_error_exit(t_data *data, char *error_msg)
{
	printf(COLOR_RED"%s\n"COLOR_NORMAL, error_msg);
	ft_exit(data);
}

int	ft_exit(t_data *data)
{
	ft_free_texture_image(data);
	ft_free_mlx(data);
	ft_free_garbage_collector(data);
	exit(0);
}
