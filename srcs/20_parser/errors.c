#include "cub3D.h"

//Return input error and quit properly 
void	ft_input_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* Error checking map */
int	ft_error_check_map(t_data *input, char *msg)
{
	printf("%s\n", msg);
	//free(input);
    exit(EXIT_FAILURE);
}

/* Error reading map */
void	ft_error_empty_map(t_data *input, char *map)
{
	printf(RED"Error:\nCan't read map\n"NORMAL);
	free(map);
	free(input);
    exit(EXIT_FAILURE);
}

/* Return fd error, free and quit properly */
void	ft_fd_error(char *msg, char *map, t_data *input)
{
	ft_putendl_fd(msg, 2);
	free(map);
	free(input);
	exit(EXIT_FAILURE);
}