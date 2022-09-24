#include "cub3D.h"

void	ft_draw_vertical_texture_line(t_data *data, int column)
{
	//double	wall_height;
	//double	percent_h_wall;
	//int	y_print;

	//wall_height = WALL_HEIGHT_FACTOR * 1 / data->ray_tab[column].ray_len;
	//i = 0;
	//while (i < (int)wall_height)
	//{

	//	y_print = (WINDOW_HEIGHT) / 2.0 - wall_height / 2.0 + (double)i;
	//	if (y_print >=0 && y_print < WINDOW_HEIGHT)
	//	{

	//	}
	//	i++;
	//}
}



void	ft_print_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ft_draw_vertical_line(data, i, 300 * 1 / data->ray_tab[i].ray_len, data->ray_tab[i].hit_wall_type);
		ft_draw_vertical_texture_line(data, i);
		i++;
	}
}

