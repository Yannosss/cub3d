/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:05:47 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:05:48 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_img_color(t_data *data, t_img *img, double percent_h_wall,
	t_ray *ray)
{
	int	x_texture;
	int	y_texture;

	(void)data;
	x_texture = (int)(ray->percent_w_wall * img->width);
	y_texture = (int)(percent_h_wall * img->height);
	return (*(int *)(img->addr + (y_texture * img->line_len
			+ x_texture * (img->bpp / 8))));
}
