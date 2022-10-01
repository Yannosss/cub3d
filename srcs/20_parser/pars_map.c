/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:09 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 18:20:52 by jbatoro          ###   ########.fr       */
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
void	ft_print_map(t_data *data, char **content)
{
	int y;
	int x;

	y = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"MAP\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (content[x][y] == '\0')
			{
				printf(" ");
				x++;
			}
			else
				printf("%c", content[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
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
				ft_error_exit(data, "Error:\nWrong file content");
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_reverse_map(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"REVERSE MAP\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{	
			if (content[i][j] == '\0')
			{
				printf(" ");
				j++;
			}
			else
				printf("%c", content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
}
int	ft_check_borders(t_data *data)
{
	//printf("%s", data->map[0]);
	//printf("%s", data->map[87]);
	ft_check_one_line(data, data->map[0]);
	//ft_print_reverse_map(data, data->map);
	ft_check_one_line(data, data->map[data->map_width -1]);
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
	//ft_print_map(data, data->map);
	ft_check_valid_char(data);
	ft_check_player(data);
	//ft_print_map(data, data->map);
	ft_check_map_is_closed(data);
	ft_check_borders(data);
	//printf("pos %lf %lf\n", data->player.x, data->player.y); 
	return (0);
}


	/*ft_check_one_line(data, data->file_content[data->map_start]);
	ft_check_one_line(data, data->file_content[data->map_start
		+ data->map_height -1]);
	return (0);
	*/