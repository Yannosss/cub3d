#include "cub3D.h"

void	ft_error_exit(t_data *data, char *error_msg)
{
	printf(COLOR_RED"%s\n"COLOR_NORMAL, error_msg);
	ft_exit(data);
}

void	ft_exit(t_data *data)
{
    (void)data;
    exit(0);
// fct recuperer de minishell, a adapter

//	int	i;

//	ft_free_garbage_collector(data);
//	i = 0;
//	while (i < 1024)
//	{
//		close(i);
//		i++;
//	}
//	exit(0);
}

