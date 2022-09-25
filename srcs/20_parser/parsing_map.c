#include "cub3D.h"

/*void	ft_get_map_size(t_data *data)
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
}

int	ft_check_map_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map_width || !data->map_height)
		ft_error_check_map(data, "Error:\nEmpty line, parsing abort");
	while (i < data->map_width)
	{
		j = 0;
		while(j < data->map_height)
		{
			if(data->nb_player > 1)
				return(ft_error_check_map(data, "Error:\nMore than one player in the map"));
			if ((data->nb_player == 0) && (i == data->map_width - 1))
				return(ft_error_check_map(data, "Error:\nNo player in the map"));
			ft_is_valid_char(data, i, j);
			j++;
		}
		i++;
	}
	int len = data->map_width - 1;
	ft_check_one_line(data, data->map[0]);
	ft_check_one_line(data, data->map[len]);
	ft_map_is_surrounded_by_walls(data);
	data->map[data->player.pos[0]][data->player.pos[1]] = '0';
	return(0);
}

int	ft_map_is_surrounded_by_walls(t_data *data)
{
	int i; 
	int j;

	i = 1;
	while(i < data->map_width -1)
	{
		j = 1;
		while (j < data->map_height -1)
		{
			if (data->map[i][j] == '0')
			{
				if (ft_is_valid_pos(data->map[i][j + 1])
					|| ft_is_valid_pos(data->map[i][j - 1])
					|| ft_is_valid_pos(data->map[i + 1][j])
					|| ft_is_valid_pos(data->map[i - 1][j]))
						ft_error_check_map(data, "Error:\nMap isn't surrounded by wall");
			}
			j++;
		}
		i++;
	}
	return (0);
}

*/

void	ft_get_map_size(t_data *data)
{
	char **map;
	size_t len;
	int map_height;
	int  map_width;

	len = 0;
	map = data->file_content;
	map_height = data->map_start;
	while (map[map_height])
	{
		map_width = 0;
		while(map[map_height][map_width])
		{
			//printf("%c\n", map[map_height][map_width]);
			if ((map_height > 0) && ft_strlen(map[map_height]) > len)
				len = ft_strlen(map[map_height]);
			map_width++;
			if (!map[map_height])
				break;
		}
		data->map_height++;
		map_height++;
	}
	data->map_width = len;
}


int	ft_fill_map(t_data *data)
{
	int i;
	int j;
	int start;

	start = data->map_start;
	i  = 0;
	while(i < data->map_height)
	{
		j = 0;
		while(j < data->map_width)
		{
			//printf("%c", data->file_content[start][j]);
			data->pars_map[i][j] = data->file_content[start][j];
			j++;
			if(data->file_content[start][i] == ' ')
				data->pars_map[i][j] = '1';
				//printf(COLOR_RED"EMPTY\n"COLOR_NORMAL);
			if (j > data->map_width)
				data->pars_map[i][j] = '\0';
		}
		i++;
		start++;
	}
	return(0);
}

int	ft_is_valid_pos(char c)
{
	if (c == ' ' || c == '\0')
		return(1);
	return(0);
}

/***********************************************************
1- Check that there are only 0, 1, space, N, S, E, W
2- Check that thre is only ONE N, S, E OR W
3- Check that the file_content is closed by walls alias '1'
************************************************************/
int	ft_map_is_surrounded_by_walls(t_data *data)
{
	int i; 
	int j;

	i = 1;
	while(i < data->map_height -1)
	{
		j = 1;
		while (j < data->map_width -1)
		{
			if (data->map[i][j] == '0')
			{
				if (ft_is_valid_pos(data->map[i][j + 1])
					|| ft_is_valid_pos(data->map[i][j - 1])
					|| ft_is_valid_pos(data->map[i + 1][j])
					|| ft_is_valid_pos(data->map[i - 1][j]))
						ft_error_check_map(data, "Error:\nMap isn't surrounded by wall");
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_valid_char(t_data *data, int i, int j)
{
	char pos;

	pos = data->map[i][j];
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
	{
		//printf("%c\n", pos);
		data->nb_player++;
		data->player.initial_direction = pos;
		data->player.pos[0] = i;
		data->player.pos[1] = j;
		return (0);
	}
	if (pos != ' ' && pos != '1' && pos != '0' && pos != '\0')
		return(ft_error_check_map(data, "Error:\nInvalid characters in map"));
	return(0);
}

int	ft_check_one_line(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_error_check_map(data, "Error:\nMap isn't surrounded by wall");
		i++;
	}
	return(0);
}

int	ft_check_map_content(t_data *data)
{
	int	i;
	int	j;
	int len;

	i = 0;
	if (!data->map_width || !data->map_height)
		ft_error_check_map(data, "Error:\nEmpty line, parsing abort");
	while (i < data->map_height)
	{
		j = 0;
		while(j < data->map_width)
		{
			if(data->nb_player > 1)
				return(ft_error_check_map(data, "Error:\nMore than one player in the map"));
			if ((data->nb_player == 0) && (i == data->map_height - 1))
				return(ft_error_check_map(data, "Error:\nNo player in the map"));
			ft_is_valid_char(data, i, j);
			j++;
		}
		i++;
	}
 	len = data->map_height;
	ft_check_one_line(data, data->map[0]);
	ft_check_one_line(data, data->map[len]);
	ft_map_is_surrounded_by_walls(data);
	data->map[data->player.pos[0]][data->player.pos[1]] = '0';
	return(0);
}

int	ft_malloc_map(t_data *data)
{
	int i;

	i  = 0;
	data->pars_map = malloc(sizeof(char*) * (data->map_width));
	if (!data->pars_map)
		ft_error_check_map(data, "error: malloc allocation failed");
	while(i < data->map_width)
	{
		data->pars_map[i] = malloc(sizeof(char*) * data->map_height);
		i++;
	}
	return(0);
}

void	ft_reverse_map(t_data *data, char **old_map)
{
	int i;
	int	j;
	int map_height;
	int map_width;

	map_height = data->map_width;
	map_width = data->map_height;

	i = 0;
	data->map = malloc(sizeof(char*) * (data->map_height));
	if (!data->map)
		ft_error_check_map(data, "error: malloc allocation failed");
	while(i < data->map_height)
	{
		data->map[i] = malloc(sizeof(char*) * data->map_width);
		i++;
	}
	i = 0;
	printf("len = %d\n", data->map_height);
	printf("len = %d\n", data->map_width);
	printf("OLD MAP\n");
	ft_print_map(data, old_map);
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			//printf("%c\n", old_map[i][j]);
			data->map[i][j] = old_map[j][i];
			printf("%d\n", j);
			printf("WITDH = %d\n", data->map_width);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_print_map(data, data->map);
}

/*------------------------------------------------------------
- Get map dimensions
- Allocate space for the map
- Parsing of the map parser la map : check des conditions
--------------------------------------------------------------*/
int	ft_get_map(t_data *data)
{
	ft_get_map_size(data);
	ft_malloc_map(data);
	ft_fill_map(data);
	ft_reverse_map(data, data->pars_map);
	//ft_check_map_content(data);
	return(0);
}