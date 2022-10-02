/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:09 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/02 11:49:51 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_map_size(t_data *data)
{
	char	**map;
	size_t	len;
	int		map_height;
	int		map_width;

	len = 0;
	map = data->file_content;
	map_height = data->map_start;
	while (map[map_height])
	{
		map_width = 0;
		while (map[map_height][map_width])
		{
			if (ft_strlen(map[map_height]) > len)
				len = ft_strlen(map[map_height]);
			map_width++;
		}
		data->map_height++;
		map_height++;
	}
	data->map_width = len;
}

int	ft_fill_map(t_data *data)
{
	int	i;
	int	j;

	ft_malloc_map(data);
	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (!data->file_content[j + data->map_start][i])
				break ;
			else
			{
				if (data->file_content[j + data->map_start][i] == ' ')
					data->map[i][j] = '\0';
				else
					data->map[i][j] = data->file_content
					[j + data->map_start][i];
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_check_valid_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{
			if (ft_is_valid_char(data->map[i][j]))
				ft_error_exit(data, "Error: wrong file or map content");
			j++;
		}
		i++;
	}
	return (0);
}

/*------------------------------------------------------------
  - Get map dimensions
  - Allocate space for the map
  - Parsing of the map parser la map : check des conditions
  --------------------------------------------------------------*/
int	ft_get_map(t_data *data)
{
	ft_get_map_size(data);
	ft_fill_map(data);
	ft_check_valid_char(data);
	ft_check_player(data);
	ft_check_map_is_closed(data);
	ft_check_borders(data);
	return (0);
}
