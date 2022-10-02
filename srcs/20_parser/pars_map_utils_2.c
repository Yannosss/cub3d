/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:06 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/02 11:48:11 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_error_doublon(t_data *data, char *s1)
{
	if (s1)
		ft_error_exit(data, "Error: wrong file content");
	return (1);
}

void	ft_malloc_map(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	data->map = ft_malloc(data, sizeof(char *) * (data->map_width));
	if (!data->map)
		ft_error_exit(data, "Error: malloc allocation failed");
	while (i < data->map_width)
	{
		data->map[i] = ft_malloc(data, sizeof(char *) * data->map_height);
		k = 0;
		while (k < data->map_height)
		{
			data->map[i][k] = '\0';
			k++;
		}
		i++;
	}
}

int	ft_is_valid_pos(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}

int	ft_is_valid_char(char pos)
{
	if (pos != '1' && pos != '0' && pos != '\0'
		&& pos != 'N' && pos != 'S' && pos != 'W'
		&& pos != 'E')
		return (1);
	return (0);
}

int	ft_check_map_is_closed(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->map_width -1)
	{
		j = 1;
		while (j < data->map_height -1)
		{
			if (data->map[i][j] == '0')
			{
				if (!ft_is_valid_pos(data->map[i][j + 1])
					||!ft_is_valid_pos(data->map[i][j - 1])
					||!ft_is_valid_pos(data->map[i + 1][j])
					||!ft_is_valid_pos(data->map[i - 1][j]))
					ft_error_exit(data, "Error: map isn't surrounded by walls");
			}
			j++;
		}
		i++;
	}
	return (0);
}
