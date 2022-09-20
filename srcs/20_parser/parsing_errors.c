#include "cub3D.h"

//Return data error and quit properly 
void	ft_input_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* Error checking map */
int	ft_error_check_map(t_data *data, char *msg)
{
	printf("%s\n", msg);
	(void)data;
	//free(data);
	// free garbage 
    exit(EXIT_FAILURE);
}

/* Error reading map */
void	ft_error_empty_map(t_data *data, char *map)
{
	printf(COLOR_RED"Error:\nCan't read map\n"COLOR_NORMAL);
	free(map);
	free(data);
    exit(EXIT_FAILURE);
}

/* Return fd error, free and quit properly */
void	ft_fd_error(char *msg, char *map, t_data *data)
{
	ft_putendl_fd(msg, 2);
	free(map);
	free(data);
	exit(EXIT_FAILURE);
}