
#include "cub3D.h"
/********************** DEBUG *******************************/
//print the map + map's values 
void	ft_print_map(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"Format OK\n"COLOR_NORMAL);
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			printf(COLOR_RED"["COLOR_NORMAL);
			printf("%c", content[i][j]);
			printf(COLOR_RED"]"COLOR_NORMAL);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
}
/************************************************************/