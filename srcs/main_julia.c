#include "cub3D.h"

int main(int ac, char **av)
{
	t_img	input;

    ft_check_input_and_format(ac, av);
	ft_check_map(&input, av[1]);
    return(0);
}