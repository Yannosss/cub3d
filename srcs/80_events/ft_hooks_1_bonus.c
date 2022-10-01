/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:26 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 17:54:49 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3D.h"

//void	ft_rotate_left(t_data *data)
//{
//	data->player.direction -= ROTATION_SPEED;
//	if (data->player.direction > 360.0 * M_PI / 180.0)
//		data->player.direction -= 360.0 * M_PI / 180;
//	if (data->player.direction < 0.0)
//		data->player.direction += 360.0 * M_PI / 180;
//	data->player.cos_direction = cos(data->player.direction);
//	data->player.sin_direction = sin(data->player.direction);
//}

//void	ft_rotate_right(t_data *data)
//{
//	data->player.direction += ROTATION_SPEED;
//	if (data->player.direction > 360.0 * M_PI / 180.0)
//		data->player.direction -= 360.0 * M_PI / 180;
//	if (data->player.direction < 0.0)
//		data->player.direction += 360.0 * M_PI / 180;
//	data->player.cos_direction = cos(data->player.direction);
//	data->player.sin_direction = sin(data->player.direction);
//}

//int	ft_move_player(int key, t_data *data)
//{
//	if (key == XK_w)
//		ft_move_up(data);
//	if (key == XK_s)
//		ft_move_down(data);
//	if (key == XK_a)
//		ft_move_left(data);
//	if (key == XK_d)
//		ft_move_right(data);
//	if (key == 65361)
//		ft_rotate_left(data);
//	if (key == 65363)
//		ft_rotate_right(data);
//	if (key == XK_Escape)
//		ft_exit(data);
//	return (0);
//}

//int	ft_handle_event(t_data *data)
//{
//	ft_print_background(data);
//	ft_draw_player_orientation(data);
//	ft_generate_3d_word_image(data);
//	ft_print_map_in_2d(data);
//	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);
//	return (0);
//}
