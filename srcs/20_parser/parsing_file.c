#include "cub3D.h"

/*---------------------------------------------------------
1- Check format extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
---------------------------------------------------------*/
void	ft_check_input_and_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error(COLOR_RED"Error:\nWrong input: ./so_long [file.cub]"COLOR_NORMAL);
	if ((ft_strlen(argv[1]) <= 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error(COLOR_RED"Error:\nWrong file format"COLOR_NORMAL);
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error(COLOR_RED"Error:\nWrong format: file must be [.cub]"COLOR_NORMAL);
}

int	ft_is_dir_valid(t_data *data, char **direction)
{
	return(0);
}

int	ft_check_dir_order(t_data *data, char a, char b)
{
	int	i;
	int	j;
	char **tmp;

	i = 0;
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			if (data->file_content[i][j] != ' ')
			{
				if (data->file_content[i][j] == a && data->file_content[i][j + 1] == b)
				{
					tmp = ft_split(data->file_content[i], ' ');
					if (tmp[2])
						printf("Not OK direction format\n");
					else	
						printf("ok, only two elements\n");
					printf("STR = %s\n", tmp[0]);
					printf("STR = %s\n", tmp[1]);
					
					//ft_is_dir_valid(data, tmp);
					ft_free_split(tmp);
				}
			}
			j++;
		}
		i++;
	}
	return(0);
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

int	ft_is_map_first(t_data *data)
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
					return(1);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return(0);
}