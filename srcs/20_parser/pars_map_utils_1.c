/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:04 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 18:20:31 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
int	ft_is_player(char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' 
		|| pos == 'W')
		return (1);
	return (0);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	ft_get_angle_from_cardinal(char c)
{
	if (c == 'N')
		return (270 * M_PI / 180.0);
	if (c == 'S')
		return (90 * M_PI / 180.0);
	if (c == 'E')
		return (0);
	else
		return (180 * M_PI / 180.0);
}

int	ft_check_one_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (i < data->map_height)
		{
			if (line[i] == '0')
				ft_error_exit(data, "Error:\nMap isn't surrounded by walls");
			i++;
		}
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
				ft_error_exit(data, "Error:\nMore than one player in the map");
			if (ft_is_player(data->map[i][j]))
				ft_get_player_pos(data, i, j);
			j++;
		}
		i++;
	}
	if (data->nb_player == 0)
		ft_error_exit(data, "Error:\nNo player in the map");
	return (0);
}

int	ft_is_valid_char(char pos)
{
	if ( pos != '1' && pos != '0' && pos != '\0'
		&& pos != 'N' && pos != 'S' && pos != 'W'
		&& pos != 'E')
		return (1);
	return (0);
}