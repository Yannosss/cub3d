#include "cub3D.h"

/************** ft_parser *********************************
1- Check map extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
2- Map must be surrounded by walls :  O has to be surrounded by 0 or 1
if space is found arround 0 -> map is invalid.
3- il peut y avoir des ligne vides
4- il n'y a qu'un Player

**********************************************************/

/********************** DEBUG *******************************/

//print the map + map's values 
void	ft_print_map(t_data *input)
{
	int i;
	int j;

	i = 0;
	printf(GREEN"Format OK\n"NORMAL);
	while (input->map[i])
	{
		j = 0;
		while (input->map[i][j])
		{
			printf("%c", input->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("WITDH = %d\n", input->map_width);
}
/************************************************************/


/*Check if map is valid */
int	ft_get_map(t_data *input, char *file)
{
	input->map = ft_read_map(input, file);
	return (0);
}

/* Create the map */
char	**ft_create_map(char *map, t_data *input)
{
	char	**final_map;

	if (map[0] == '\0')
		ft_error_empty_map(input, map);
	final_map = ft_split(map, '\n');
	free (map);
	return (final_map);
}

/* Read map */
char	**ft_read_map(t_data *input, char *file)
{
	char	*str;
	char	*map;
	int		fd;

	input->map_width = 0;
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
		input->map_width++;
	}
	free(str);
	close(fd);
	return (ft_create_map(map, input));
}

/***********************************************************
1- Check that there are only 0, 1, space, N, S, E, W
2- Check that thre is only ONE N, S, E OR W
3- Check that the map is closed by walls alias '1'
************************************************************/
int	ft_is_valid_char(t_data *input, char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		{
			input->player++;
			return (0);
		}
	if (pos != ' ' && pos != '1' && pos != '0')
		return(ft_error_check_map(input, "error: invalid map"));
	return(0);
}

int	ft_map_is_surrounded_by_walls(t_data *input, int pos_y, int pos_x)
{
	char pos;

	pos = input->map[pos_x][pos_y];
	//printf("len = %zu\n", ft_strlen(input->map[pos_x]));
	if (pos == 0 && pos_x < 4) // have the len of each line
	{
		if (input->map[pos_x + 1][pos_y] != '1')
			return(ft_error_check_map(input, "error: map is not surrounded by walls"));
	}
	return (0);
}

int	ft_check_map(t_data *input)
{
	int	i;
	int	j;

	i = 0;
	while (input->map[i])
	{
		j = 0;
		while (input->map[i][j])
		{
			if(input->player > 1)
				return(ft_error_check_map(input, "error: more than one player"));
			ft_is_valid_char(input, input->map[i][j]);
			ft_map_is_surrounded_by_walls(input, i, j);
			i++;
		}
		j++;
	}
	return(0);
}


int	ft_parser(t_data *input, char **av)
{
	ft_get_map(input, av[1]);
	ft_check_map(input);
	return(0);
}