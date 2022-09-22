#include "cub3D.h"

/* Create the map */
char	**ft_create_file(char *map, t_data *data)
{
	char	**final_map;

	if (map[0] == '\0')
		ft_error_empty_map(data, map);
	final_map = ft_split(map, '\n');
	free (map);
	return (final_map);
}

/* Read map */
char	**ft_read_file(t_data *data, char *file_input)
{
	char	*str;
	char	*file;
	int		fd;

	str = "";
	file = ft_strdup("");
	fd = open(file_input, O_RDONLY);
	if (fd < 0)
		ft_fd_error(COLOR_RED"Error:\nCan't create fd"COLOR_NORMAL, file, data);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL || str[0] == '\n')
			break ;
		file = ft_strjoin(file, str);
		//inclure garbage
		free(str);
	}
	free(str);
	close(fd);
	return (ft_create_file(file, data));
}

/*--------------------------- PARSER -------------------------------------
1- Get the content of the file
2- Check if directions conformed with subject requierements
3- Check if colors conformed with subject requirements
4- If map exist in the file, get it into a new char** > data->map
	Else, return error.
--------------------------------------------------------------------------*/

int	ft_parser(t_data *data, char **av)
{
	int index_c;

	index_c = 0; 
	data->file_content = ft_read_file(data, av[1]);
	if (!data->file_content)
		return(ft_error_check_map(data, "error: empty file"));
	index_c = ft_parse_colums(data);
	data->map_start = index_c; //get le debut de la map;
	// map_check 
	ft_get_map(data);
	return (0);
}