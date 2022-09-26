#include "cub3D.h"

void    ft_init_colors(t_data *data)
{
    data->ceiling_clr.checked = 0;
    data->ceiling_clr.r = 0;
    data->ceiling_clr.g = 0;
    data->ceiling_clr.b = 0;
    data->floor_clr.r = 0;
    data->floor_clr.g = 0;
    data->floor_clr.b = 0;
    data->floor_clr.checked = 0;
}

void    ft_init_textures(t_data *data)
{
    data->textures.north = NULL;
    data->textures.south = NULL;
    data->textures.west = NULL;
    data->textures.east = NULL;
}

int    ft_init_struct(t_data *data)
{

    data->map = NULL;
    data->map_height= 0;
    data->map_width = 0;
    data->nb_player = 0;
    data->id_filled = 0;
    data->file_content = NULL;
    data->pars_map = NULL;
    data->player.pos[0] = 0;
    data->player.pos[1] = 0;
    data->floor_clr.color;
    data->player.initial_direction = 0;
    ft_init_textures(data);
    ft_init_colors(data);
    return(0);
}

int main(int ac, char **av)
{
	t_data *data;
	data = malloc((sizeof(t_data)));

    ft_check_input_and_format(ac, av);
    ft_init_struct(data);
    ft_parser(data, av);
    /// DEBUG //
   //ft_print_file_content(&data, data.file_content);
  ft_print_reverse_map(data, data->map);
    	printf(COLOR_YELLOW"FLOOR R: %d\n"COLOR_NORMAL, data->floor_clr.r);
	printf(COLOR_YELLOW"FLOOR G : %d\n"COLOR_NORMAL, data->floor_clr.g);
	printf(COLOR_YELLOW"FLOOR B: %d\n"COLOR_NORMAL, data->floor_clr.b);
    return(0);
}