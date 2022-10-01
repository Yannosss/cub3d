/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:09 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 15:13:46 by jbatoro          ###   ########.fr       */
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

int	ft_check_map_content(t_data *data)
{
	int	i;
	int	j;

	i = data->map_start;
	if (!data->map_width || !data->map_height)
		ft_error_exit(data, "Error:\nEmpty line, parsing abort");
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			if (data->nb_player > 1)
				ft_error_exit(data, "Error:\nMore than one player in the map");
			ft_is_valid_char(data, i, j);
			j++;
		}
		i++;
	}
	if (data->nb_player == 0)
		ft_error_exit(data, "Error:\nNo player in the map");
	ft_map_is_surrounded_by_walls(data);
	ft_check_one_line(data, data->file_content[data->map_start]);
	ft_check_one_line(data, data->file_content[data->map_start
		+ data->map_height -1]);
	return (0);
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
					data->map[i][j] = 'x';
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

/*------------------------------------------------------------
  - Get map dimensions
  - Allocate space for the map
  - Parsing of the map parser la map : check des conditions
  --------------------------------------------------------------*/
int	ft_get_map(t_data *data)
{
	ft_get_map_size(data);
	ft_check_map_content(data);
	ft_fill_map(data);
	return (0);
}
