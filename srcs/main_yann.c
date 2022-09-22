#include "cub3D.h"

static void ft_create_small_map(t_data *data);
static void	ft_read_map_light(t_data *data, char ** argv);
static void ft_create_ray(t_data *data, t_ray *ray);

// lancer avec cmd ./cub3D srcs/maps/map_03.cub
int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc((sizeof(t_data)));
	ft_data_initialisation(data);

	//ft_read_map_light(data, argv);
	ft_create_small_map(data);

	ft_init_mlx(data);
	//mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

	// ************ affichage bande verte test (debut) **************
	//t_ray ray_test;
	//ft_create_ray(data, &ray_test);
	//int decalage = 90;
	//while (1)
	//{
	//	ft_black_screen(data);
	//	ft_print_map_in_2d(data);
	//	int i = -30;
	//	while (i < 30)
	//	{
	//		ray_test.theta_rad = ((i+decalage) % 360 * M_PI / 180);
	//		ft_compute_ray_hit_point(data, &ray_test);
	//		ft_compute_ray_len(data, &ray_test);
	//		//ft_draw_vertical_line(data, 6* i, 400 - 100 * ray_test.ray_len);
	//		ray_test.ray_len = ray_test.ray_len *  cos(i * M_PI /180);
	//		ft_draw_vertical_line(data, WINDOW_WIDTH/2 + 6* i, 300 * 1/ray_test.ray_len);
	//		i++;
	//	}
	//	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);
	//	decalage++;
	//	usleep(20000);
	//}
	// ************ affichage bande verte test (fin) **************


	//int x;
	//x = 0;
	while (1)
	{
		ft_black_screen(data);
		ft_print_map_in_2d(data);
		ft_generate_3D_word_image(data);


		ft_print_map_in_2d(data);
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

	data->player.x = 2.5;
	data->player.y = 3.5;
	data->player.direction = 0;

}

static void ft_create_ray(t_data *data, t_ray *ray)
{
	ray->start_point.x = 2.5;
	ray->start_point.y = 3.5;
	ray->theta_rad = 290 * M_PI / 180;


}
