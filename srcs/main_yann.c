#include "cub3D.h"

static void ft_create_small_map(t_data *data);
static void	ft_read_map_light(t_data *data, char ** argv);

// lancer avec cmd ./cub3D srcs/maps/map_03.cub
int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc((sizeof(t_data)));
	ft_data_initialisation(data);

	ft_read_map_light(data, argv);

	ft_init_mlx(data);
	//mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

	// print map
	ft_print_map_in_2d(data);
	// print player
	ft_img_pixel_put(data, data->player.x, data->player.y, MLX_COLOR_RED);

	// refresh display
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);




	int x;
	x = 0;
	while (1)
	{
	//	if (x > 400)
	//		x = 10;
	//	ft_img_pixel_put(data, x, 5, MLX_COLOR_GREEN); // pixel vert
	//	ft_img_pixel_put(data, x-1, 5, MLX_COLOR_BLACK); // pixel noir
	////mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

	//	usleep(10000);
	//	x++;
	}

}

// lit une map de taille 10*10 situee dans argv[1]
// et positionne joueur en (1.5,1.5) oriente nord
static void	ft_read_map_light(t_data *data, char ** argv)
{
	ft_parser(data, argv);
    ft_print_map(data);
	data->map_width = 10;
    data->map_height = 10;
		data->player.x = 1.5;
	data->player.y = 1.5;
	data->player.direction = 90;
}

static void ft_create_small_map(t_data *data)
{
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
}
