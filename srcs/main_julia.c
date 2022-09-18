#include "cub3D.h"

int    ft_init_struct(t_data *data)
{
    data = malloc(sizeof(t_data));
    if (!data)
        return (-1);
   
    //data->textures = NULL;
    data->map = NULL;
    data->map_height= 0;
    data->map_width = 0;
    data->nb_player = 0;
    data->file_content = NULL;
    /*data->textures->north = NULL;
    data->textures->south = NULL;
    data->textures->west = NULL;
    data->textures->east = NULL;
    data->textures->no = 0;
    data->textures->so = 0;
    data->textures->we = 0;
    data->textures->ea = 0;*/
    
    return(0);
}

int main(int ac, char **av)
{
	t_data	data;

    ft_check_input_and_format(ac, av);
    ft_init_struct(&data);
    ft_parser(&data, av);
    printf("ID = %s\n", data.textures->save[0]);
    // debug
    //ft_print_map(&data, data.file_content);
    return(0);
}