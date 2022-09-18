#include "cub3D.h"
/***********************************************************
1- Check that there are only 0, 1, space, N, S, E, W
2- Check that thre is only ONE N, S, E OR W
3- Check that the file_content is closed by walls alias '1'
************************************************************/

int	ft_file_content_is_surrounded_by_walls(t_data *data, int pos_y, int pos_x)
{
	char pos;

	pos = data->file_content[pos_x][pos_y];
	//printf("len = %zu\n", ft_strlen(data->file_content[pos_x]));
	if (pos == 0 && pos_x < 4) // have the len of each line
	{
		if (data->file_content[pos_x + 1][pos_y] != '1')
			return(ft_error_check_map(data, "error: file_content is not surrounded by walls"));
	}
	return (0);
}

int	ft_check_file_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			if(data->nb_player > 1)
				return(ft_error_check_map(data, "error: more than one player"));
			ft_is_valid_char(data, data->file_content[i][j]);
			ft_file_content_is_surrounded_by_walls(data, i, j);
			i++;
		}
		j++;
	}
	return(0);
}