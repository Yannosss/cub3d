/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:00 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/02 11:24:40 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_get_nb(t_data *data, char *str)
{
	int	i;
	int	nb;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_exit(data, "Error: color r, b or b is not digit");
		i++;
	}
	nb = ft_atoi(str);
	if (nb > 255 || nb < 0)
		ft_error_exit(data, "Error: color r, b or b is not between 0 and 256");
	return (nb);
}

int	ft_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	ft_are_id_filled(t_data *data)
{
	if (data->textures.north && data->textures.south
		&& data->textures.west && data->textures.east
		&& data->floor_clr.checked && data->ceiling_clr.checked)
	{
		data->id_filled = 1;
		return (1);
	}
	return (0);
}

int	ft_is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\r' && line[i] != '\f' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' '
			|| line[i] == '\t' || line[i] == '\v'
			|| line[i] == '\n' || line[i] == '\r'
			|| line[i] == '\f'))
		i++;
	return (i);
}
