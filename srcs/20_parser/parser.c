#include "cub3D.h"

/************** ft_parser *********************************
1- Check map extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
2- Map must be surrounded by walls :  O has to be surrounded by 0 or 1
if space is found arround 0 -> map is invalid.
3- il peut y avoir des ligne vides
4- il n'y a qu'un Player

**********************************************************/

/*Check if map is valid */
int	ft_get_file_content(t_data *data, char *file)
{
	data->file_content= ft_read_map(data, file);
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
		ft_free(str);
		data->map_width++;
	}
	free(str);
	close(fd);
	return (ft_create_map(map, data));
}


int	ft_parser(t_data *data, char **av)
{
	ft_get_file_content(data, av[1]);
	if (ft_check_file(data) < 0)
		printf(COLOR_GREEN"Map is not before infos\n"COLOR_NORMAL);
	//ft_check_directions(data);
	//ft_check_map(data);
	return(0);
}