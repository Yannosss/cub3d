/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:09 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/02 11:49:10 by jbatoro          ###   ########.fr       */
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
		if (line[i] != '0')
			i++;
		else
			ft_error_exit(data, "Error: map isn't surrounded by walls");
	}
	return (0);
}
