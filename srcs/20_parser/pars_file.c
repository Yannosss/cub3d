/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:03 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/03 19:31:27 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*---------------------------------------------------------
  1- Check format extension : only .cub are allowed
  and a file nammed ".cub" only must be consired as an error.
  ---------------------------------------------------------*/
void	ft_check_input_and_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error(COLOR_RED"Error: wrong input: ./cub3D [file.cub]"
			COLOR_NORMAL);
	if (!ft_strrchr(argv[1], '.'))
		ft_input_error(COLOR_RED"Error: wrong file format"COLOR_NORMAL);
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error(COLOR_RED"Error: wrong format: file must be [.cub]"
			COLOR_NORMAL);
}

/*-------------------------------------------------------------------------
// get_texture : envoie de la string
// j'envoie &line[index_l], etdata->texture->id 
// je fais un split : je check si j' ai bien !str[2] 
// Ensuite je check  je peux ouvrir str[1] : sinon error
// si je peux : je stock str[1] dans data->texture->no
---------------------------------------------------------------------------*/
char	*ft_get_texture(t_data *data, char *file)
{
	char	**temp;
	char	*path;

	temp = NULL;
	temp = ft_split_garbage_collector(data, file, ' ');
	if (temp[2])
		ft_error_exit(data, "Error: argument after path texture");
	path = ft_malloc(data, sizeof(char *) * ft_strlen(file) + 1);
	if (!path)
		ft_error_exit(data, "Error: malloc allocation failed");
	ft_strncpy(path, temp[1], ft_strlen(file));
	ft_free_split_garbage_collector(data, temp);
	return (path);
}

int	ft_get_clr(t_data *data, char *line, int type)
{
	char	**tmp;

	tmp = NULL;
	while (*line == ' ')
		line++;
	tmp = ft_split_garbage_collector(data, line, ',');
	if (!tmp)
		ft_error_exit(data, "Error: malloc allocation failed");
	if (!tmp[0] ||!tmp[1] || !tmp[2] || tmp[3])
		ft_error_exit(data, "Error: wrong rgb format");
	if (type == FLOOR)
		ft_get_floor_clr(data, tmp);
	else if (type == CEILING)
		ft_get_ceil_clr(data, tmp);
	ft_free_split_garbage_collector(data, tmp);
	return (0);
}

int	ft_is_id_valid(t_data *data, char *line, int index_l)
{
	if (ft_are_id_filled(data))
		return (0);
	if (ft_strncmp(&line[index_l], "C ", 2) == 0 && !data->ceiling_clr.r)
		ft_get_clr(data, &line[index_l + 2], CEILING);
	else if (ft_strncmp(&line[index_l], "F ", 2) == 0 && !data->floor_clr.r)
		ft_get_clr(data, &line[index_l + 2], FLOOR);
	else if (ft_strncmp(&line[index_l], "NO ", 3) == 0
		&& ft_error_doublon(data, data->textures.north))
		data->textures.north = ft_get_texture(data, &line[index_l]);
	else if (ft_strncmp(&line[index_l], "SO ", 3) == 0
		&& ft_error_doublon(data, data->textures.south))
		data->textures.south = ft_get_texture(data, &line[index_l]);
	else if (ft_strncmp(&line[index_l], "WE ", 3) == 0
		&& ft_error_doublon(data, data->textures.west))
		data->textures.west = ft_get_texture(data, &line[index_l]);
	else if (ft_strncmp(&line[index_l], "EA ", 3) == 0
		&& ft_error_doublon(data, data->textures.east))
		data->textures.east = ft_get_texture(data, &line[index_l]);
	else if (!ft_is_empty_line(&line[index_l]))
		ft_error_exit(data, "Error: wrong textures");
	return (0);
}

int	ft_parse_directions(t_data *data)
{
	int	index_c;
	int	index_l;

	index_c = 0;
	index_l = 0;
	while (data->file_content[index_c])
	{
		index_l = ft_skip_space(data->file_content[index_c]);
		ft_is_id_valid(data, data->file_content[index_c], index_l);
		if (data->id_filled == 1)
			break ;
		index_c++;
	}
	return (index_c);
}
