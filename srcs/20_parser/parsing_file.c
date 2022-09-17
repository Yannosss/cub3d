#include "cub3D.h"

//Check format extension
void	ft_check_input_and_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error(COLOR_RED"Error:\nWrong input: ./so_long [file.cub]"COLOR_NORMAL);
	if ((ft_strlen(argv[1]) <= 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error(COLOR_RED"Error:\nWrong file format"COLOR_NORMAL);
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error(COLOR_RED"Error:\nWrong format: file must be [.cub]"COLOR_NORMAL);
}

int	ft_check_first_line(t_data *data, int index, int j)
{
	int count;

	count = 0;
	while (data->file_content[index][count])
	{
		if (data->file_content[index][j] != 'N')
			return (-1);
		else if (data->file_content[index][j] == 'N')
		{
			//printf("char = %c\n", data->file_content[index][j]);
			count++;
			if (data->file_content[index][count] == '0'
				|| data->file_content[index][count] == '1')
					return(-1);
		}
		else
			count++;
	}
	return(0);
}

int	ft_check_file(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			if(data->file_content[i][j] != ' ')
			{
				if (ft_check_first_line(data, i, j) < 0)
					ft_error_check_file_content(data, "error: wrong file content");
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return(0);
}

int	ft_check_directions(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			if(data->file_content[i][j] != ' ')
			{
				if (data->file_content[i][j] == 'N' && data->file_content[i][j + 1] == 'O')
					printf("OK Found NO\n");
					//recup ce qu'il y a apres NO 
				else
					ft_error_check_file_content(data, "error: wrong directions");
			}
			j++;
		}
		i++;
	}
	return(0);
}