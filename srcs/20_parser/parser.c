#include "cub3D.h"

/************** ft_parser *********************************
1- Check map extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
2- Map must be surrounded by walls :  O has to be surrounded by 0 or 1
if space is found arround 0 -> map is invalid.
3- il peut y avoir des ligne vides
4- il n'y a qu'un Player

**********************************************************/

//debeug : print the map 
void	ft_print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
}

/*Check if map is valid */
int	ft_check_map(t_img *input, char *file)
{
	// to add a la structure generale 
	char **map;

	map = ft_read_map(input, file);
	ft_print_map(map);
	return (0);
}

/* Create the map */
char	**ft_create_map(char *map, t_img *input)
{
	char	**final_map;

	(void)input;
	if (map[0] == '\0')
		ft_error_empty_map(input, map);
	final_map = ft_split(map, '\n');
	free (map);
	return (final_map);
}

/* Read map */
char	**ft_read_map(t_img *input, char *file)
{
	char	*str;
	char	*map;
	int		fd;

	(void)input;
	str = "";
	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_fd_error(RED"Error:\nCan't create fd"NORMAL, map, input);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL || str[0] == '\n')
			break ;
		map = ft_strjoin(map, str);
		free(str);
		//map->width++;
	}
	free(str);
	close(fd);
	return (ft_create_map(map, input));
}

// utils
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

//Check format extension
void	ft_check_input_and_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error(RED"Error:\nWrong input: ./so_long [file.cub]"NORMAL);
	if ((ft_strlen(argv[1]) <= 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error(RED"Error:\nWrong file format"NORMAL);
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error(RED"Error:\nWrong format: file must be [.cub]"NORMAL);
    //temporaire
    else
        printf("Format OK\n");
}