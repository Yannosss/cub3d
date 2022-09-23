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
	printf(COLOR_RED"%s\n"COLOR_NORMAL, msg);
	ft_free_garbage_collector(data);
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
void	ft_fd_error(char *msg, char *file, t_data *data)
{
	printf(COLOR_RED"%s\n"COLOR_NORMAL, msg);
	free(file);
	ft_free_garbage_collector(data);
	exit(EXIT_FAILURE);
}