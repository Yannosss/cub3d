/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:02 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:03 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_floor_clr(t_data *data, char **rgb)
{
	data->floor_clr.r = ft_get_nb(data, rgb[0]);
	data->floor_clr.g = ft_get_nb(data, rgb[1]);
	data->floor_clr.b = ft_get_nb(data, rgb[2]);
	data->floor_clr.checked = 1;
	data->floor_clr.color = ft_rgb_to_int(data->floor_clr.r, data->floor_clr.g,
			data->floor_clr.b);
}

void	ft_get_ceil_clr(t_data *data, char **rgb)
{
	data->ceiling_clr.r = ft_get_nb(data, rgb[0]);
	data->ceiling_clr.g = ft_get_nb(data, rgb[1]);
	data->ceiling_clr.b = ft_get_nb(data, rgb[2]);
	data->ceiling_clr.checked = 1;
	data->ceiling_clr.color = ft_rgb_to_int(data->ceiling_clr.r,
			data->ceiling_clr.g, data->ceiling_clr.b);
}
