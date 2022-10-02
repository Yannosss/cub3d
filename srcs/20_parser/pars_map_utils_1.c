/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:04 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/02 11:51:00 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_column(t_data *data, int i, int j)
{
	while (i < data->map_width)
	{
		if (data->map[i][j] == '0')
			ft_error_exit(data, "Error: map isn't surrounded by walls");
		i++;
	}
	return (0);
}

int	ft_check_borders(t_data *data)
{
	ft_check_one_line(data, data->map[0]);
	ft_check_one_line(data, data->map[data->map_width -1]);
	ft_check_column(data, 0, 0);
	ft_check_column(data, 0, data->map_height -1);
	return (0);
}

void	ft_get_player_pos(t_data *data, int i, int j)
{
	data->nb_player++;
	data->player.direction = ft_get_angle_from_cardinal
		(data->map[i][j]);
	data->player.x = (double)i + 0.51;
	data->player.y = (double)j + 0.51;
	data->map[i][j] = '0';
}

int	ft_check_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{
			if (data->nb_player > 1)
				ft_error_exit(data, "Error: more than one player in the map");
			if (ft_is_player(data->map[i][j]))
				ft_get_player_pos(data, i, j);
			j++;
		}
		i++;
	}
	if (data->nb_player == 0)
		ft_error_exit(data, "Error: no player in the map");
	return (0);
}
