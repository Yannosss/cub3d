#include "cub3D.h"



// lancer avec cmd ./cub3D srcs/maps/map_03.cub
int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc((sizeof(t_data)));
	ft_data_initialisation(data);

	//ft_read_map_light(data, argv);
	ft_create_small_map(data);

	ft_init_mlx(data);

	int width;
	int heigth;
	void *img;
	//img  = mlx_xpm_file_to_image (data->mlx, "./textures/debug_north.xpm", &width, &heigth);
	//printf("return %p\n", img);
	//mlx_put_image_to_window(data->mlx, data->window, img, 0, 0);

	////img.addr = mlx_get_data_addr(img.img_pt, &(img.bpp),
	////		&(img.line_len), &(img.endian));
	//usleep(20000000);

	while (1)
	{
		ft_black_screen(data);
		ft_generate_3D_word_image(data);
		ft_print_map_in_2d(data);


		//ft_print_map_in_2d(data);
		//mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);
		//data->player.direction += 0.2;
		ft_increment_player_direction(data, 0.02); //0.785398


		mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

		usleep(20000);
	}

}

// lit une map de taille 10*10 situee dans argv[1]
// et positionne joueur en (1.5,1.5) oriente nord
static void	ft_read_map_light(t_data *data, char ** argv)
{
	//ft_parser(data, argv);
    //ft_print_map(data);
	//data->map_width = 10;
    //data->map_height = 10;
	//data->player.x = 2.5;
	//data->player.y = 3.5;
	//data->player.direction = 90;
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

	data->player.x = 2.9;
	data->player.y = 4.1;
	data->player.direction = 0 * M_PI / 180;
	data->player.cos_direction = cos(data->player.direction);
	data->player.sin_direction = sin(data->player.direction);
	data->player.tan_direction = tan(data->player.direction);


}

static void ft_create_ray(t_data *data, t_ray *ray)
{
	ray->start_point.x = 2.5;
	ray->start_point.y = 3.5;
	ray->theta_rad = 290 * M_PI / 180;


}

void	ft_increment_player_direction(t_data *data, double inc)
{
	data->player.direction += inc;
	if (data->player.direction > 360.0 * M_PI / 180.0)
		data->player.direction -= 360.0 * M_PI / 180;
	if (data->player.direction < 0.0)
		data->player.direction += 360.0 * M_PI / 180;

	data->player.cos_direction = cos(data->player.direction);
	data->player.sin_direction = sin(data->player.direction);
	data->player.tan_direction = tan(data->player.direction);
}
