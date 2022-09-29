#include "cub3D.h"
void	ft_get_map_size(t_data *data)
{
	char **map;
	size_t len;
	int map_height;
	int  map_width;

	len = 0;
	map = data->file_content;
	map_height = data->map_start;
	//ft_print_file_content(data, map);
	while (map[map_height])
	{
		map_width = 0;
		//printf("%s\n", map[map_height]);
		while(map[map_height][map_width])
		{
			//printf("[%d]\n", map_height);
			if (ft_strlen(map[map_height]) > len)
				len = ft_strlen(map[map_height]);
			map_width++;
		}
		data->map_height++;
		map_height++;
	}
	data->map_width = len;
//	printf("WITDH = %d\n", data->map_width);
//	printf("HEIGHT = %d\n", data->map_height);
}

int	ft_is_valid_pos(char c)
{
	//printf(COLOR_GREEN"%c\n"COLOR_NORMAL, c);
	/*if (c == '\0' || c == ' ')*/
	if (c == '1' || c == '0'
		|| c == 'N' || c == 'S' 
		|| c == 'E' || c == 'W')
		return(0);
	return(1);
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
	int start;

	start = data->map_start;
	i = data->map_start;
	while (i < data->map_height + data->map_start -1)
	{
		j = 0;
		//while(data->file_content[i][j])
		while(j < data->map_width)
		{	
			if (data->file_content[i][j] == '0')
			{
				//printf("%c",data->file_content[i][j]);
				if (ft_is_valid_pos(data->file_content[i][j + 1])
					|| ft_is_valid_pos(data->file_content[i][j - 1])
					|| ft_is_valid_pos(data->file_content[i + 1][j])
					|| ft_is_valid_pos(data->file_content[i - 1][j]))
					ft_error_check_map(data, "Error:\nMap isn't surrounded by wall");
			}
			//printf(COLOR_RED"%c"COLOR_NORMAL, data->file_content[i][j]);
			j++;
		}
		//printf("\n");
		i++;
	}
	return (0);
}
int	ft_check_one_line(t_data *data, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_error_check_map(data, "Error:\n");
		i++;
	}
	return(0);
}

double	ft_get_angle_from_cardinal(char c)
{
	if (c == 'N')
		return(270 * M_PI / 180.0);
	if (c == 'S')
		return(90 * M_PI / 180.0);
	if (c == 'E')
		return(0);
	if (c == 'W')
		return(180 * M_PI / 180.0);
}


int	ft_is_valid_char(t_data *data, int i, int j)
{
	char pos;
	pos = data->file_content[i][j];
	//printf("%c\n", data->map[i][j]);
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
	{
		//printf("%c\n", pos);
		data->nb_player++;
		data->player.direction = ft_get_angle_from_cardinal(pos);
		data->player.x = (double)i + 0.5;
		data->player.y = (double)j + 0.5;
		return (0);
	}
	if (pos != ' ' && pos != '1' && pos != '0' && pos != '\0')
	{
		return(ft_error_check_map(data, "Error:\nInvalid characters in map"));
	}
	return(0);
}

int	ft_check_map_content(t_data *data)
{
	int	i;
	int	j;
	int len;
	
	len = data->map_start + data->map_height -1;
	ft_print_file_content(data, data->file_content);
	//printf("%d\n", data->map_start);
	i = data->map_start;
	if (!data->map_width || !data->map_height)
		ft_error_check_map(data, "Error:\nEmpty line, parsing abort");
	while (data->file_content[i])
	{
		j = 0;
		while(data->file_content[i][j])
		{
			//printf("%c", data->file_content[i][j]);
			if(data->nb_player > 1)
				return(ft_error_check_map(data, "Error:\nMore than one player in the map"));
			ft_is_valid_char(data, i, j);
			j++;
		}
		//printf("\n");
		i++;
	}
	if ((data->nb_player == 0))
		return(ft_error_check_map(data, "Error:\nNo player in the map"));
	ft_map_is_surrounded_by_walls(data);
	ft_check_one_line(data, data->file_content[data->map_start]);
	ft_check_one_line(data, data->file_content[len]);
	return(0);
}

void	ft_malloc_map(t_data *data)
{
	int i;
	int k;
 
	i = 0;
	data->map = ft_malloc(data, sizeof(char*) * (data->map_width));
	if (!data->map)
		ft_error_exit(data, "Error:\nMalloc allocation failed");
	while(i < data->map_width)
	{
		data->map[i] = malloc(sizeof(char*) * data->map_height);
		k = 0;
		while(k < data->map_height)
		{
			data->map[i][k] = 'x';
			k++;
		}
		i++;
	}
}

int	ft_fill_map(t_data *data)
{
	int i;
	int	j;

	ft_malloc_map(data);
    j = 0;
	while(j < data->map_height)
	{
		i = 0;
		while(i < data->map_width)
		{
			if (!data->file_content[j + data->map_start][i])
				break;
		   	else
			{
				if (data->file_content[j + data->map_start][i] == ' ')
					data->map[i][j] = 'x';
				else
					data->map[i][j] = 
						data->file_content[j + data->map_start][i];
			}
			i++;
		}
		j++;
	}
	return(0);
}

/*------------------------------------------------------------
- Get map dimensions
- Allocate space for the map
- Parsing of the map parser la map : check des conditions
--------------------------------------------------------------*/
int	ft_get_map(t_data *data)
{
	ft_get_map_size(data);
	ft_check_map_content(data);
	ft_fill_map(data);
	return(0);
}