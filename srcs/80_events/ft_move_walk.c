/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_walk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:35:08 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 18:35:09 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_forward(t_data *data)
{
	double	next_x;
	double	next_y;

	if (data->player.is_moving_foward)
	{
		next_x = data->player.x + cos(data->player.direction) * MOVE_SPEED;
		next_y = data->player.y + sin(data->player.direction) * MOVE_SPEED;
		if (!ft_is_on_wall(data, next_x, next_y))
		{
			data->player.x = next_x;
			data->player.y = next_y;
		}
	}
}

void	ft_move_backward(t_data *data)
{
	double	next_x;
	double	next_y;

	if (data->player.is_moving_backward)
	{
		next_x = data->player.x - cos(data->player.direction) * MOVE_SPEED;
		next_y = data->player.y - sin(data->player.direction) * MOVE_SPEED;
		if (!ft_is_on_wall(data, next_x, next_y))
		{
			data->player.x = next_x;
			data->player.y = next_y;
		}
	}
}

void	ft_move_left(t_data *data)
{
	double	rad;
	double	next_x;
	double	next_y;

	if (data->player.is_moving_left)
	{
		rad = (data->player.direction) + (90 * M_PI / 180.0);
		next_x = data->player.x - cos(rad) * MOVE_SPEED;
		next_y = data->player.y - sin(rad) * MOVE_SPEED;
		if (!ft_is_on_wall(data, next_x, next_y))
		{
			data->player.x = next_x;
			data->player.y = next_y;
		}
	}
}

void	ft_move_right(t_data *data)
{
	double	rad;
	double	next_x;
	double	next_y;

	if (data->player.is_moving_right)
	{
		rad = (data->player.direction) - (90 * M_PI / 180.0);
		next_x = data->player.x - cos(rad) * MOVE_SPEED;
		next_y = data->player.y - sin(rad) * MOVE_SPEED;
		if (!ft_is_on_wall(data, next_x, next_y))
		{
			data->player.x = next_x;
			data->player.y = next_y;
		}
	}
}
