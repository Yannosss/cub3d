#include "cub3D.h"

int	ft_fill_map(t_data *data)
{
	int i;
	int	j;
	int k;
    int start;

	i = 0;
    start = data->map_start -1;
    printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
	data->map = malloc(sizeof(char*) * (data->map_width));
	if (!data->map)
		ft_error_check_map(data, "error: malloc allocation failed");
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
					data->map[i][j] = data->file_content[j + data->map_start][i];
			}
			i++;
		}
		j++;
	}
	ft_print_map(data, data->map);
	return(0);
}

/*    i = 0;
    //printf("index = %d\n", i);
	while(i < data->map_width)
	{
		j = 0;
        start = data->map_start - 1;
        //printf("index i= %d\n", i);
		//printf("index start = %d\n", start);
       //	printf("%s\n", data->file_content[start]);
		while(j < data->map_height)
		{
			//printf("%s\n", data->file_content[start]);
			//printf("%c", data->file_content[start][i]);
          //  printf("%c", data->file_content[start][i]);
			if (!data->file_content[start][i])
				data->map[i][j] = ' ';
		   	else
				data->map[i][j] = data->file_content[start][i];
        	//printf("%c", data->map[i][j]);
			j++;
			start++;
		}
		i++;
       // printf("\n");
	}
	ft_print_map(data, data->map);
	return(0);
}*/