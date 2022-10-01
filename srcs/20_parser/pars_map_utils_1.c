/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:04 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:05 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_is_valid_pos(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (0);
	return (1);
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

	(void)data;
	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_error_exit(data, "Error:\n");
		i++;
	}
	return (0);
}

int	ft_is_valid_char(t_data *data, int i, int j)
{
	char	pos;

	pos = data->file_content[i][j];
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
	{
		data->nb_player++;
		data->player.direction = ft_get_angle_from_cardinal(pos);
		data->player.x = (double)(i - data->map_start + 1.0) + 0.51;
		data->player.y = (double)j - 1.0 + 0.51;
		data->file_content[i][j] = '0';
		return (0);
	}
	if (pos != ' ' && pos != '1' && pos != '0' && pos != '\0')
		ft_error_exit(data, "Error:\nInvalid characters in map");
	return (0);
}
