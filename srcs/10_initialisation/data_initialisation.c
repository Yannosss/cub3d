/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:05:57 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 19:42:19 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_img(t_data *data)
{
	data->img.img_pt = NULL;
	data->img.addr = NULL;
	data->img.bpp = -1;
	data->img.line_len = -1;
	data->img.endian = -1;
	data->img.width = -1;
	data->img.height = -1;
}

void	ft_init_player(t_data *data)
{
	data->player.x = -1.0;
	data->player.y = -1.0;
	data->player.direction = -1.0;
	data->player.cos_direction = -1;
	data->player.sin_direction = -1;
	data->player.tan_direction = -1;
	data->player.is_moving_foward = 0;
	data->player.is_moving_backward = 0;
	data->player.is_moving_right = 0;
	data->player.is_moving_left = 0;
	data->player.is_rotating_right = 0;
	data->player.is_rotating_left = 0;
}

void	ft_init_colors(t_data *data)
{
	data->ceiling_clr.checked = 0;
	data->ceiling_clr.color = 0;
	data->ceiling_clr.r = 0;
	data->ceiling_clr.g = 0;
	data->ceiling_clr.b = 0;
	data->floor_clr.r = 0;
	data->floor_clr.g = 0;
	data->floor_clr.b = 0;
	data->floor_clr.color = 0;
	data->floor_clr.checked = 0;
}

void	ft_init_textures(t_data *data)
{
	data->textures.north = NULL;
	data->textures.south = NULL;
	data->textures.west = NULL;
	data->textures.east = NULL;
	data->textures.north_img.img_pt = NULL;
	data->textures.south_img.img_pt = NULL;
	data->textures.west_img.img_pt = NULL;
	data->textures.east_img.img_pt = NULL;
	data->textures.north_img.addr = NULL;
	data->textures.south_img.addr = NULL;
	data->textures.west_img.addr = NULL;
	data->textures.east_img.addr = NULL;
}

void	ft_data_initialisation(t_data *data)
{
	data->garbage_collector = NULL;
	data->map = NULL;
	data->file_content = NULL;
	data->nb_player = 0;
	data->id_filled = -1;
	data->map_width = 0;
	data->map_height = 0;
	data->d_camera = (((double)WINDOW_WIDTH - 1.0) / 2.0) / (tan (FOV / 2.0));
	data->mlx = NULL;
	data->window = NULL;
	data->map_start = 0;
	ft_init_img(data);
	ft_init_textures(data);
	ft_init_colors(data);
	ft_init_player(data);
}
