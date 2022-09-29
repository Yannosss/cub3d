#include "cub3D.h"

void	ft_input_error(char *msg)
{
	ft_putendl_fd(msg, 2);
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
