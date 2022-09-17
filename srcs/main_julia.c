#include "cub3D.h"

int    ft_init_struct(t_data *input)
{
    input = malloc(sizeof(t_data));
    if (!input)
        return (-1);
    input->map = NULL;
    input->map_length = 0;
    input->map_width = 0;
    input->nb_player = 0;
    return(0);
}

int main(int ac, char **av)
{
	t_data	input;

    ft_check_input_and_format(ac, av);
    ft_init_struct(&input);
    ft_parser(&input, av);
    // debug
    ft_print_map(&input);
    return(0);
}