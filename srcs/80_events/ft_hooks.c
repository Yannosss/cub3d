/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:34:43 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/02 15:55:53 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_move_player_press(int key, t_data *data)
{
	if (key == XK_w)
		data->player.is_moving_foward = 1;
	if (key == XK_s)
		data->player.is_moving_backward = 1;
	if (key == XK_a)
		data->player.is_moving_left = 1;
	if (key == XK_d)
		data->player.is_moving_right = 1;
	if (key == 65361)
		data->player.is_rotating_left = 1;
	if (key == 65363)
		data->player.is_rotating_right = 1;
	if (key == XK_Escape)
		ft_exit(data);
	return (0);
}

int	ft_move_player_release(int key, t_data *data)
{
	if (key == XK_w)
		data->player.is_moving_foward = 0;
	if (key == XK_s)
		data->player.is_moving_backward = 0;
	if (key == XK_a)
		data->player.is_moving_left = 0;
	if (key == XK_d)
		data->player.is_moving_right = 0;
	if (key == 65361)
		data->player.is_rotating_left = 0;
	if (key == 65363)
		data->player.is_rotating_right = 0;
	return (0);
}

void	ft_move(t_data *data)
{
	ft_rotate_left(data);
	ft_rotate_right(data);
	ft_move_forward(data);
	ft_move_backward(data);
	ft_move_left(data);
	ft_move_right(data);
}

int	ft_handle_event(t_data *data)
{
	ft_print_background(data);
	ft_generate_3d_word_image(data);
	ft_move(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);
	return (0);
}
