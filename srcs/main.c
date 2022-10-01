/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:36 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:37 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_check_input_and_format(argc, argv);
	ft_data_initialisation(&data);
	ft_parser(&data, argv);
	ft_init_mlx(&data);
	ft_open_textures(&data);
	mlx_hook(data.window, 2, (1L << 0), &ft_move_player, &data);
	mlx_hook(data.window, 17, (1L << 17), ft_exit, &data);
	mlx_loop_hook(data.mlx, &ft_handle_event, &data);
	mlx_loop(data.mlx);
	exit(0);
}
