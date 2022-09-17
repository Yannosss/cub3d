
#include "cub3D.h"
/********************** DEBUG *******************************/
//print the map + map's values 
void	ft_print_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"Format OK\n"COLOR_NORMAL);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			printf("%c", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
}
/************************************************************/