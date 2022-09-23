#include "cub3D.h"

void	ft_get_map_size(t_data *data)
{
	char **map;
	size_t len;
	int  i;
	int j;

	len = 0;
	map = data->file_content;
	i = data->map_start;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if ((i > 0) && ft_strlen(map[i]) > len)
				len = ft_strlen(map[i]);
			j++;	
		}
		data->map_width++;
		i++;
	}
	data->map_height = len;
}

int	ft_malloc_map(t_data *data)
{
	int i;

	i  = 0;
	data->map = malloc(sizeof(char**) * (data->map_width));
	if (!data->map)
		ft_error_check_map(data, "error: malloc allocation failed");
	while(i < data->map_width)
	{
		data->map[i] = malloc(sizeof(char*) * data->map_height + 1);
		i++;
	}
	return(0);
}

int	ft_fill_map(t_data *data)
{
	int i;
	int j;
	int start;

	start = data->map_start;
	i  = 0;
	while(i < data->map_width)
	{
		j = 0;
		while(j < data->map_height)
		{
			//printf("%c", data->file_content[start][j]);
			while(data->file_content[start][j] == ' ')
			{
				data->map[i][j] = '1';
				j++;
			}
			data->map[i][j] = data->file_content[start][j];
			j++;
			if(data->file_content[start][i] == ' ')
				data->map[i][j] = '1';
				//printf(COLOR_RED"EMPTY\n"COLOR_NORMAL);
			if (j > data->map_height)
				data->map[i][j] = '\0';
		}
		i++;
		start++;
	}
	return(0);
}

/***********************************************************
1- Check that there are only 0, 1, space, N, S, E, W
2- Check that thre is only ONE N, S, E OR W
3- Check that the file_content is closed by walls alias '1'
************************************************************/
int	ft_file_content_is_surrounded_by_walls(t_data *data, int i, int j)
{
//	verifier qu on est pas a la premiere place || a la derniere place
	if (data->map[i][j] == '0' && (i > 0 ) && (j <= data->map_height))
	{
		/*printf("CHAR = %c\n", data->map[i][j]);
		printf(COLOR_YELLOW"CHAR DROITE = %c\n"COLOR_NORMAL, data->map[i][j+ 1]);
		printf(COLOR_GREEN"CHAR  GAUCHE = %c\n"COLOR_NORMAL, data->map[i][j - 1]);
		printf(COLOR_CYAN"CHAR HAUT = %c\n"COLOR_NORMAL, data->map[i + 1][j]);
		printf(COLOR_RED"CHAR BAS = %c\n"COLOR_NORMAL, data->map[i - 1][j]);
		printf("---------------------------------------\n");*/
		if (data->map[i][j + 1] != '0' && data->map[i][j + 1] != '1')
		{
			//printf(COLOR_YELLOW"FOUND %s\n ligne : %d"COLOR_NORMAL, data->map[i], i);
			ft_error_check_map(data, "map isn't surrounded by wall");
		}
		if (data->map[i][j - 1] != '0' && data->map[i][j - 1] != '1')
		{
		//	printf(COLOR_GREEN"FOUND\n"COLOR_NORMAL);
			ft_error_check_map(data, "map isn't surrounded by wall");
		}
		if (data->map[i + 1][j] != '0' && data->map[i + 1][j] != '1')
		{
			//printf(COLOR_CYAN"FOUND\n"COLOR_NORMAL);
			ft_error_check_map(data, "map isn't surrounded by wall");
		}
		if (data->map[i - 1][j] != '0' && data->map[i - 1][j] != '1')
		{
			//printf(COLOR_RED"FOUND\n"COLOR_NORMAL);
			ft_error_check_map(data, "map isn't surrounded by wall");
		}
	}
	return (0);
}

int	ft_is_valid_char(t_data *data, int i, int j)
{
	char pos;

	pos = data->map[i][j];
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
	{
		data->nb_player++;
		data->map[i][j] = '2';
		data->player.pos[0]= i;
		data->player.pos[1] = j;
		return (0);
	}
	if (pos != ' ' && pos != '1' && pos != '0')
		return(ft_error_check_map(data, "error: invalid characters in map"));
	return(0);
}

int	ft_check_map_content(t_data *data)
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
			if ((data->nb_player == 0) && (i == data->map_width - 1))
				return(ft_error_check_map(data, "error: no player in the game"));
			//ft_is_valid_char(data, i, j);
			//ft_file_content_is_surrounded_by_walls(data, i, j);
			j++;
		}
		i++;
	}
	return(0);
}

// calculer la taille de la map
// malloquer la map
// parser la map : check des conditions
int	ft_get_map(t_data *data)
{
	ft_get_map_size(data);
	//ft_malloc_map(data);
	//ft_fill_map(data);
	//ft_check_map_content(data);
	return(0);
}