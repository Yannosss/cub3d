/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:36 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 17:43:16 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	ft_print_all(t_data *data)
{
    //ft_print_map(data, data->map);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
    printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_RED"TEXTURE NORTH: %s\n"COLOR_NORMAL, data->textures.north);
	printf(COLOR_RED"TEXTURE SOUTH: %s\n"COLOR_NORMAL, data->textures.south);
	printf(COLOR_RED"TEXTURE WEST: %s\n"COLOR_NORMAL, data->textures.west);
	printf(COLOR_RED"TEXTURE EAST: %s\n"COLOR_NORMAL, data->textures.west);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_YELLOW"FLOOR R: %d\n"COLOR_NORMAL, data->floor_clr.r);
	printf(COLOR_YELLOW"FLOOR G : %d\n"COLOR_NORMAL, data->floor_clr.g);
	printf(COLOR_YELLOW"FLOOR B: %d\n"COLOR_NORMAL, data->floor_clr.b);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_YELLOW"CEILING R: %d\n"COLOR_NORMAL, data->ceiling_clr.r);
	printf(COLOR_YELLOW"CEILING G: %d\n"COLOR_NORMAL, data->ceiling_clr.g);
	printf(COLOR_YELLOW"CEILING B: %d\n"COLOR_NORMAL, data->ceiling_clr.b);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_check_input_and_format(argc, argv);
	ft_data_initialisation(&data);
	ft_parser(&data, argv);
	//ft_print_all(&data);
	/*printf("pos %lf %lf\n", data.player.x, data.player.y); // a sup a la fin
	ft_init_mlx(&data);
	ft_open_textures(&data);
	mlx_hook(data.window, 2, (1L << 0), &ft_move_player, &data);
	mlx_hook(data.window, 17, (1L << 17), ft_exit, &data);
	mlx_loop_hook(data.mlx, &ft_handle_event, &data);
	mlx_loop(data.mlx);*/
	exit(0);
}
