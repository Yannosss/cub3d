#include "cub3D.h"

/************** ft_parser *********************************
1- Check map extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
2- Map must be surrounded by walls :  O has to be surrounded by 0 or 1
if space is found arround 0 -> map is invalid.
3- il peut y avoir des ligne vides
4- il n'y a qu'un Player

**********************************************************/
// utils
int	ft_is_empty_line(char *map, int i, int j)
{
	int count;

	count = 0;
	
}


/*Check if map is valid */
int	ft_get_map(t_data *data, char *file)
{
	data->map = ft_read_map(data, file);
	return (0);
}

/* Create the map */
char	**ft_create_map(char *map, t_data *data)
{
	char	**final_map;

	if (map[0] == '\0')
		ft_error_empty_map(data, map);
	final_map = ft_split(map, '\n');
	free (map);
	return (final_map);
}

/* Read map */
char	**ft_read_map(t_data *data, char *file)
{
	char	*str;
	char	*map;
	int		fd;

	data->map_width = 0;
	str = "";
	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_fd_error(COLOR_RED"Error:\nCan't create fd"COLOR_NORMAL, map, data);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL || str[0] == '\n')
			break ;
		map = ft_strjoin(map, str);
		free(str);
		data->map_width++;
	}
	free(str);
	close(fd);
	return (ft_create_map(map, data));
}

/***********************************************************
1- Check that there are only 0, 1, space, N, S, E, W
2- Check that thre is only ONE N, S, E OR W
3- Check that the map is closed by walls alias '1'
************************************************************/
int	ft_is_valid_char(t_data *data, char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		{
			data->nb_player++;
			return (0);
		}
	if (pos != ' ' && pos != '1' && pos != '0')
		return(ft_error_check_map(data, "error: invalid map"));
	return(0);
}

int	ft_map_is_surrounded_by_walls(t_data *data, int pos_y, int pos_x)
{
	char pos;

	pos = data->map[pos_x][pos_y];
	//printf("len = %zu\n", ft_strlen(data->map[pos_x]));
	if (pos == 0 && pos_x < 4) // have the len of each line
	{
		if (data->map[pos_x + 1][pos_y] != '1')
			return(ft_error_check_map(data, "error: map is not surrounded by walls"));
	}
	return (0);
}

int	ft_check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if(data->nb_player > 1)
				return(ft_error_check_map(data, "error: more than one player"));
			ft_is_valid_char(data, data->map[i][j]);
			ft_map_is_surrounded_by_walls(data, i, j);
			i++;
		}
		j++;
	}
	return(0);
}

int	ft_check_first_line(t_data *data, int index, int j)
{
	int count;

	count = 0;
	while (data->map[index][count])
	{
		if (data->map[index][j] != 'N')
			return (-1);
		else if (data->map[index][j] == 'N')
		{
			//printf("char = %c\n", data->map[index][j]);
			count++;
			if (data->map[index][count] == '0'
				|| data->map[index][count] == '1')
					return(-1);
		}
		else
			count++;
	}
	return(0);
}

int	ft_check_file(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if(data->map[i][j] != ' ')
			{
				if (ft_check_first_line(data, i, j) < 0)
					ft_error_check_map(data, "error: wrong file content");
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return(0);
}

int	ft_check_directions(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if(data->map[i][j] != ' ')
			{
				if (data->map[i][j] == 'N' && data->map[i][j + 1] == 'O')
					printf("OK Found NO\n");
				else
					ft_error_check_map(data, "error: wrong directions");
			}
			j++;
		}
		i++;
	}
	return(0);
}


int	ft_parser(t_data *data, char **av)
{
	ft_get_map(data, av[1]);
	if (ft_check_file(data) < 0)
		printf(COLOR_GREEN"Map is not before infos\n"COLOR_NORMAL);
	ft_check_directions(data);
	//ft_check_map(data);
	return(0);
}