#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc((sizeof(t_data)));
	ft_data_initialisation(data);

	data->map_width = 4;
    data->map_height = 3;
	data->map = malloc(sizeof(char *) * data->map_width); //nb of columm 4
	int i = 0;
	while (i < data->map_width)
	{
		data->map[i] = malloc(sizeof(char) * data->map_height); //nb of line 3
		i++;
	}
	// map
	// 1 1 1 1
	// 1 N 0 1
	// 1 1 1 1

	data->map[0][0] = '1';
	data->map[0][1] = '1';
	data->map[0][2] = '1';

	data->map[1][0] = '1';
	data->map[1][1] = '0';
	data->map[1][2] = '1';

	data->map[2][0] = '1';
	data->map[2][1] = '0';
	data->map[2][2] = '1';

	data->map[3][0] = '1';
	data->map[3][1] = '1';
	data->map[3][2] = '1';


	data->player.x = 1.5;
	data->player.y = 1.5;
	data->player.direction = 90;

	ft_init_mlx(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);
	ft_img_pixel_put(data, 5, 5, MLX_COLOR_GREEN); // pixel vert



	int x;
	x = 0;
	while (1)
	{
		if (x > 400)
			x = 10;
		ft_img_pixel_put(data, x, 5, MLX_COLOR_GREEN); // pixel vert
		ft_img_pixel_put(data, x-1, 5, MLX_COLOR_BLACK); // pixel noir
	//mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

		usleep(10000);
		x++;


	}

}
