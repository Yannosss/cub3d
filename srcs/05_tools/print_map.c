
#include "cub3D.h"
/********************** DEBUG *******************************/
void	ft_print_file_content(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"FILE CONTENT\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			if (i == data->player.pos[0] && j == data->player.pos[1])
				printf(COLOR_RED"%c"COLOR_NORMAL, content[i][j]);
			else
				printf("%c", content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	//printf("WITDH = %d\n", data->map_width);
	//printf("HEIGHT = %d\n", data->map_height);
}
//print the map + map's values 
void	ft_print_reverse_map(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"Format OK\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{
			if (i == data->player.pos[0] && j == data->player.pos[1])
				printf(COLOR_RED"%c"COLOR_NORMAL, content[i][j]);
			else
				printf("[%c]", content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
}
/************************************************************/
void	ft_print_map(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"Format OK\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (i == data->player.pos[0] && j == data->player.pos[1])
				printf(COLOR_RED"%c"COLOR_NORMAL, content[i][j]);
			else
				printf("%c", content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
}