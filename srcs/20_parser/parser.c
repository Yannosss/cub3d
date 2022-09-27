#include "cub3D.h"

/*---------------------------------
Get the file stocked into a char*
Split the char* file with newline
----------------------------------*/
char	**ft_create_file(char *file, t_data *data)
{
	char	**final_file;

	if (file[0] == '\0')
		ft_error_empty_map(data, file);
	final_file = ft_split(file, '\n');
	ft_add_to_garbage_collector(data, final_file);
	free(file);
	return (final_file);
}

/*---------------------------------
Open and read the file given in arg
Stock the file into a char*
Return file content in char** splitted with newlines
----------------------------------*/
char	**ft_read_file(t_data *data, char *file_input)
{
	char	*str;
	char	*file;
	int		fd;

	str = "";
	file = ft_strdup("");
	fd = open(file_input, O_RDONLY);
	if (fd < 0)
		ft_fd_error("Error:\nCan't create fd", file, data);
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		file = ft_strjoin(file, str);		
		free(str);
	}
	free(str);
	close(fd);
	return (ft_create_file(file, data));
}

/*--------------------------- PARSER -------------------------------------
1- Get the content of the file
2- Check if directions conformed with subject requierements
3- Check if colors conformed with subject requirements
4- If map exist in the file at good position, get it into a new char** (data->map)
	Else, return error.
--------------------------------------------------------------------------*/
int	ft_parser(t_data *data, char **av)
{
	int index_c;

	index_c = 0;
	data->file_content = ft_read_file(data, av[1]);
	if (!data->file_content)
		return (ft_error_check_map(data, "Error:\nEmpty file"));
	index_c = ft_parse_directions(data);
	printf("%s\n",data->file_content[index_c]);
	while (ft_is_empty_line(data->file_content[index_c]))
	{
		printf("%s\n",data->file_content[index_c]);
		index_c++;
	}
	data->map_start = index_c;
	printf("index = %d", index_c);
	ft_get_map(data);
	return (0);
}