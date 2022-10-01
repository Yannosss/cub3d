/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:06 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 15:14:13 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_error_doublon(t_data *data, char *s1)
{
	if (s1)
		ft_error_exit(data, "error: doublons in file");
	return (1);
}

void	ft_malloc_map(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	data->map = ft_malloc(data, sizeof(char *) * (data->map_width));
	if (!data->map)
		ft_error_exit(data, "Error:\nMalloc allocation failed");
	while (i < data->map_width)
	{
		data->map[i] = ft_malloc(data, sizeof(char *) * data->map_height);
		k = 0;
		while (k < data->map_height)
		{
			data->map[i][k] = 'x';
			k++;
		}
		i++;
	}
}

/*------------------------------------------------------------
  1- Check that there are only 0, 1, space, N, S, E, W
  2- Check that thre is only ONE N, S, E OR W
  3- Check that the file_content is closed by walls alias '1'
  ------------------------------------------------------------*/
int	ft_map_is_surrounded_by_walls(t_data *data)
{
	int	i;
	int	j;
	int	start;

	start = data->map_start;
	i = data->map_start;
	while (i < data->map_height + data->map_start -1)
	{
		j = 0;
		while (j < data->map_width)
		{	
			if (data->file_content[i][j] == '0')
			{
				if (ft_is_valid_pos(data->file_content[i][j + 1])
						|| ft_is_valid_pos(data->file_content[i][j - 1])
						|| ft_is_valid_pos(data->file_content[i + 1][j])
						|| ft_is_valid_pos(data->file_content[i - 1][j]))
						ft_error_exit(data, "Error:\nMap isn't surrounded by wall");
			}
			j++;
		}
		i++;
	}
	return (0);
}
