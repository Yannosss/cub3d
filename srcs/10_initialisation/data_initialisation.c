#include "cub3D.h"

void	ft_data_initialisation(t_data *data)
{
	// check a la fin que toutes les variable de data sont initisalisees
	data->garbage_collector = NULL;
	data->map = NULL;
	data->nb_player = 0;
	data->player.x = -1.0;
	data->player.y = -1.0;
	data->player.direction = -1.0;
	data->map_height = 0;
	data->map_width = 0;
	data->mlx = NULL;
	data->window = NULL;

}
