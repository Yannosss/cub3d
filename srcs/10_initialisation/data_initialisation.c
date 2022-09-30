#include "cub3D.h"

void    ft_init_colors(t_data *data)
{
    data->ceiling_clr.checked = 0;
	data->ceiling_clr.color = 0;
    data->ceiling_clr.r = 0;
    data->ceiling_clr.g = 0;
    data->ceiling_clr.b = 0;
    data->floor_clr.r = 0;
    data->floor_clr.g = 0;
    data->floor_clr.b = 0;
	data->floor_clr.color = 0;
    data->floor_clr.checked = 0;
}

void    ft_init_textures(t_data *data)
{
    data->textures.north = NULL;
    data->textures.south = NULL;
    data->textures.west = NULL;
    data->textures.east = NULL;
}

void	ft_data_initialisation(t_data *data)
{
	// check a la fin que toutes les variable de data sont initisalisees
	data->garbage_collector = NULL;
	data->map = NULL;
	data->nb_player = 0;
	data->player.x = -1.0;
	data->player.y = -1.0;
	data->player.direction = -1.0;
	data->map_width = 0;
	data->map_height = 0;
	data->nb_player = 0;
    data->id_filled = 0;
    data->file_content = NULL;
    data->player.ction = NULL;
	data->d_camera = (((double)WINDOW_WIDTH - 1.0) / 2.0) / (tan (FOV / 2.0));
	data->mlx = NULL;
	data->window = NULL;
    ft_init_textures(data);
    ft_init_colors(data);
}

/*void    ft_init_colors(t_data *data)
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
    data->player.pos[0] = 0;
    data->player.ction = 0;
    ft_init_textures(data);
    ft_init_colors(data);
    return(0);
}*/