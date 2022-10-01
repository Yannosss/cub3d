/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:13 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:14 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_open_texture_north(t_data *data)
{
	data->textures.north_img.img_pt = mlx_xpm_file_to_image (data->mlx,
			data->textures.north, &(data->textures.north_img.width),
			&(data->textures.north_img.height));
	if (!data->textures.north_img.img_pt)
		return (1);
	data->textures.north_img.addr = mlx_get_data_addr(
			data->textures.north_img.img_pt,
			&(data->textures.north_img.bpp),
			&(data->textures.north_img.line_len),
			&(data->textures.north_img.endian));
	if (!data->textures.north_img.addr)
		return (1);
	return (0);
}

static int	ft_open_texture_south(t_data *data)
{
	data->textures.south_img.img_pt = mlx_xpm_file_to_image (data->mlx,
			data->textures.south, &(data->textures.south_img.width),
			&(data->textures.south_img.height));
	if (!data->textures.south_img.img_pt)
		return (1);
	data->textures.south_img.addr = mlx_get_data_addr(
			data->textures.south_img.img_pt,
			&(data->textures.south_img.bpp),
			&(data->textures.south_img.line_len),
			&(data->textures.south_img.endian));
	if (!data->textures.south_img.addr)
		return (1);
	return (0);
}

static int	ft_open_texture_east(t_data *data)
{
	data->textures.east_img.img_pt = mlx_xpm_file_to_image (data->mlx,
			data->textures.east, &(data->textures.east_img.width),
			&(data->textures.east_img.height));
	if (!data->textures.east_img.img_pt)
		return (1);
	data->textures.east_img.addr = mlx_get_data_addr(
			data->textures.east_img.img_pt,
			&(data->textures.east_img.bpp),
			&(data->textures.east_img.line_len),
			&(data->textures.east_img.endian));
	if (!data->textures.east_img.addr)
		return (1);
	return (0);
}

static int	ft_open_texture_west(t_data *data)
{
	data->textures.west_img.img_pt = mlx_xpm_file_to_image (data->mlx,
			data->textures.west, &(data->textures.west_img.width),
			&(data->textures.west_img.height));
	if (!data->textures.west_img.img_pt)
		return (1);
	data->textures.west_img.addr = mlx_get_data_addr(
			data->textures.west_img.img_pt,
			&(data->textures.west_img.bpp),
			&(data->textures.west_img.line_len),
			&(data->textures.north_img.endian));
	if (!data->textures.west_img.addr)
		return (1);
	return (0);
}

void	ft_open_textures(t_data *data)
{
	if (ft_open_texture_north(data) == 1
		|| ft_open_texture_south(data) == 1
		|| ft_open_texture_east(data) == 1
		|| ft_open_texture_west(data) == 1)
	{
		ft_error_exit(data, "Error: Can't open texture");
	}
}
