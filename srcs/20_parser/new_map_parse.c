#include "cub3D.h"

int	ft_fill_map(t_data *data)
{
	int i;
	int	j;
    int start;

	i = 0;
    start = data->map_start -1;
    //printf("WITDH = %d\n", data->map_width);
	//printf("HEIGHT = %d\n", data->map_height);
	data->map = malloc(sizeof(char*) * (data->map_height));
	if (!data->map)
		ft_error_check_map(data, "error: malloc allocation failed");
	while(i < data->map_height)
	{
		data->map[i] = malloc(sizeof(char*) * data->map_width + 1);
		i++;
	}
    i = 0;
    //printf("index = %d\n", i);
	while(i < data->map_width)
	{
		j = 0;
        start = data->map_start - 1;
        //printf("index i= %d\n", i);
        //printf("index j= %d\n", j);
       // printf("%s\n", data->file_content[i]);
       // ("CHAR = %c\n", data->file_content[i][j]);
		while(j < data->map_height)
		{
			//printf("%c", data->file_content[data->map_start][j]);
          //  printf("%c", data->file_content[start][i]);
            //if (!data->file_content[start][j])
			  //  data->map[i][j] = ' ';
		    data->map[i][j] = data->file_content[start][i];
            printf("%c", data->map[i][j]);
           // ft_print_file_content(data, data->map);
            //printf("%c", data->file_content[i][j]);
			j++;
            start++;
		}
		i++;
        printf("\n");
	}
	return(0);
}