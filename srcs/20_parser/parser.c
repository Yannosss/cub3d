#include "cub3D.h"

/*Check if map is valid */
int	ft_get_file_content(t_data *data, char *file)
{
	data->file_content = ft_read_file(data, file);
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

char	*ft_get_textures(t_data *data, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	char **tmp;
	//data->textures->save = malloc(sizeof(char*) * (1000 * 2));
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O')
		{
			if(data->textures->no == 1)
				exit(0);
				//return(ft_error_check_map(data,"error: already found NO"));
			printf("Found NO\n");
			tmp = ft_split(str, ' ');
			data->textures->save[j] = tmp[0];
			//printf("ID = %s\n", tmp[0]);
			data->textures->no = 1;
			//ft_free_split(tmp);
			j++;
		}
		if (str[i] == 'S' && str[i + 1] == 'O')
		{
			if(data->textures.so == 1)
				return(ft_error_check_map(data,"ERROR, already found SO"));
			printf("Found SO\n");
			tmp = ft_split(str, ' ');
			data->textures.save[j] = tmp[0];
			printf("ID = %s\n", data->textures.save[j]);
			data->textures.so = 1;
			//ft_free_split(tmp);
			j++;
		}
		if (str[i] == 'W' && str[i + 1] == 'E')
		{
			if(data->textures.we == 1)
				return(ft_error_check_map(data,"ERROR, already found WE"));
			printf("Found WE\n");
			tmp = ft_split(str, ' ');
			data->textures.save[j] = tmp[0];
			//printf("ID = %s\n", data->textures.save[j]);
			data->textures.we = 1;
			//ft_free_split(tmp);
			j++;
		}
		if (str[i] == 'E' && str[i + 1] == 'A')
		{
			if(data->textures.ea == 1)
				return(ft_error_check_map(data,"ERROR, already found EA"));
			printf("Found EA\n");
			tmp = ft_split(str, ' ');
			data->textures.save[j] = tmp[0];
			printf("ID = %s\n", data->textures.save[j]);
			data->textures.ea = 1;
			//ft_free_split(tmp);
			j++;
		}
		i++;
	}
	return(0);
}
/* Read map */
char	**ft_read_file(t_data *data, char *file_input)
{
	char	*str;
	char	*file;
	int		fd;

	data->textures->save = malloc(sizeof(char *) * 1000); //calculer bonne taille de tableau
	// garbage
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
		ft_get_textures(data, str);
		printf(" ID = %s\n", data->textures->save[0]);
		//ft_get_colors()
		file = ft_strjoin(file, str);
		//inclure garbage
		free(str);
		data->map_width++;
	}
	free(str);
	close(fd);
	return (ft_create_map(file, data));
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
	ft_read_file(data, av[1]);
	//ft_get_file_content(data, av[1]);
	//if (ft_is_map_first(data))
	//	return(ft_error_check_map(data, "error: file content is not in good order"));
	//if (ft_check_dir_order(data, 'N', 'O'))
	//	return(ft_error_check_map(data, "error: wrong directions positions"));
	//data->map = ft_get_map(data);
	//ft_check_map(data);
	return(0);
}