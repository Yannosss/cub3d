/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:34:50 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 18:34:53 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_left(t_data *data)
{
	if (data->player.is_rotating_left)
	{
		data->player.direction -= ROTATION_SPEED;
		if (data->player.direction > 360.0 * M_PI / 180.0)
			data->player.direction -= 360.0 * M_PI / 180;
		if (data->player.direction < 0.0)
			data->player.direction += 360.0 * M_PI / 180;
		data->player.cos_direction = cos(data->player.direction);
		data->player.sin_direction = sin(data->player.direction);
	}
}

void	ft_rotate_right(t_data *data)
{
	if (data->player.is_rotating_right)
	{
		data->player.direction += ROTATION_SPEED;
		if (data->player.direction > 360.0 * M_PI / 180.0)
			data->player.direction -= 360.0 * M_PI / 180;
		if (data->player.direction < 0.0)
			data->player.direction += 360.0 * M_PI / 180;
		data->player.cos_direction = cos(data->player.direction);
		data->player.sin_direction = sin(data->player.direction);
	}
}
