#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc((sizeof(t_data)));
	ft_data_initialisation(data);
	ft_init_mlx(data);

	ft_create_small_map(data);

	while (1)
	{
		ft_black_screen(data);
		ft_print_map_in_2d(data);
		ft_draw_player_orientation(data);




		mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

		usleep(20000);
	}


}



static void ft_create_small_map(t_data *data)
{
	data->map_width = 7;
    data->map_height = 6;
	data->map = malloc(sizeof(char *) * data->map_width); //nb of columm 4
	int i = 0;
	while (i < data->map_width)
	{
		data->map[i] = malloc(sizeof(char) * data->map_height); //nb of line 3
		i++;
	}
	// map
	// 1 1 1 1 1 1 1
	// 1 1 0 0 0 0 1
	// 1 0 0 0 1 1 1
	// 1 0 0 0 0 1 1
	// 1 1 1 1 1 1 1

	data->map[0][0] = '1';
	data->map[0][1] = '1';
	data->map[0][2] = '1';
	data->map[0][3] = '1';
	data->map[0][4] = '1';
	data->map[0][5] = '1';

	data->map[1][0] = '1';
	data->map[1][1] = '1';
	data->map[1][2] = '0';
	data->map[1][3] = '0';
	data->map[1][4] = '0';
	data->map[1][5] = '1';

	data->map[2][0] = '1';
	data->map[2][1] = '0';
	data->map[2][2] = '0';
	data->map[2][3] = '0';
	data->map[2][4] = '0';
	data->map[2][5] = '1';

	data->map[3][0] = '1';
	data->map[3][1] = '0';
	data->map[3][2] = '0';
	data->map[3][3] = '0';
	data->map[3][4] = '0';
	data->map[3][5] = '1';

	data->map[4][0] = '1';
	data->map[4][1] = '0';
	data->map[4][2] = '0';
	data->map[4][3] = '1';
	data->map[4][4] = '0';
	data->map[4][5] = '1';

	data->map[5][0] = '1';
	data->map[5][1] = '0';
	data->map[5][2] = '0';
	data->map[5][3] = '1';
	data->map[5][4] = '1';
	data->map[5][5] = '1';

	data->map[6][0] = '1';
	data->map[6][1] = '1';
	data->map[6][2] = '1';
	data->map[6][3] = '1';
	data->map[6][4] = '1';
	data->map[6][5] = '1';

	data->player.x = 2.5;
	data->player.y = 3.5;
	data->player.direction = 45.0 * M_PI / 180.0;
	data->player.cos_direction = cos(data->player.direction);
	data->player.sin_direction = sin(data->player.direction);
	data->player.tan_direction = tan(data->player.direction);


}


//void	ft_increment_player_direction(t_data *data, double inc)
//{
//	data->player.direction += inc;
//	if (data->player.direction > 360.0 * M_PI / 180.0)
//		data->player.direction -= 360.0 * M_PI / 180;
//	if (data->player.direction < 0.0)
//		data->player.direction += 360.0 * M_PI / 180;

//	data->player.cos_direction = cos(data->player.direction);
//	data->player.sin_direction = sin(data->player.direction);
//	data->player.tan_direction = tan(data->player.direction);
//}
