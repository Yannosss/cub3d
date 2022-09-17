#include "cub3D.h"

int    ft_init_struct(t_data *data)
{
    data = malloc(sizeof(t_data));
    if (!data)
        return (-1);
    data->map = NULL;
    data->map_height= 0;
    data->map_width = 0;
    data->nb_player = 0;
    return(0);
}

int main(int ac, char **av)
{
	t_data	data;

    ft_check_input_and_format(ac, av);
    ft_init_struct(&data);
    ft_parser(&data, av);
    // debug
    ft_print_map(&data);
    return(0);
}