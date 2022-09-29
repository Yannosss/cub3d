#include "cub3D.h"

int	ft_is_on_wall(t_data *data, double x, double y)
{
	if (data->map[(int)floor(x)][(int)floor(y)] == '1')
		return(1);
	return(0);
}

void	ft_move_up(t_data *data)
{
	double next_x;
	double next_y;

	next_x = data->player.x + cos(data->player.direction) * MOVE_SPEED;
	next_y = data->player.y + sin(data->player.direction) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}

void	ft_move_down(t_data *data)
{
	double next_x;
	double next_y;

	next_x = data->player.x - cos(data->player.direction) * MOVE_SPEED;
	next_y = data->player.y - sin(data->player.direction) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}

void	ft_rotate_left(t_data *data)
{
	data->player.direction -= ROTATION_SPEED;
	if (data->player.direction > 360.0 * M_PI / 180.0)
		data->player.direction -= 360.0 * M_PI / 180;
	if (data->player.direction < 0.0)
		data->player.direction += 360.0 * M_PI / 180;
	data->player.cos_direction = cos(data->player.direction);
	data->player.sin_direction = sin(data->player.direction);
}

void	ft_move_left(t_data *data)
{
	double rad;
	double next_x;
	double next_y;

	rad = (data->player.direction) + (90 * M_PI / 180.0);
	next_x = data->player.x - cos(rad) * MOVE_SPEED;
	next_y = data->player.y - sin(rad) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}
void	ft_move_right(t_data *data)
{
	double rad;
	double next_x;
	double next_y;

	rad = (data->player.direction) - (90 * M_PI / 180.0);
	next_x =  data->player.x - cos(rad) * MOVE_SPEED;
	next_y =  data->player.y - sin(rad) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}
void	ft_rotate_right(t_data *data)
{
	data->player.direction += ROTATION_SPEED;
	if (data->player.direction > 360.0 * M_PI / 180.0)
		data->player.direction -= 360.0 * M_PI / 180;
	if (data->player.direction < 0.0)
		data->player.direction += 360.0 * M_PI / 180;
	data->player.cos_direction = cos(data->player.direction);
	data->player.sin_direction = sin(data->player.direction);
}
int	ft_move_player(int key, t_data *data)
{

	if (key == XK_w)
		ft_move_up(data);
	if (key == XK_s)
		ft_move_down(data);
	if (key == XK_a)
		ft_move_left(data);
	if (key == XK_d)
		ft_move_right(data);
	if (key == 65361)
		ft_rotate_left(data);
	if (key == 65363)
		ft_rotate_right(data);
	if (key == XK_Escape)
		ft_exit(data);

}
int ft_handle_event(t_data *data)
{
	//ft_black_screen(data);
	ft_print_background(data);
	ft_draw_player_orientation(data);
	ft_generate_3d_word_image(data);
	ft_print_map_in_2d(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);
	//printf("%lf\n", data->player.y);
}


int	main(int argc, char **argv)
{
	double x;
	double y;

	t_data *data;
	data = malloc((sizeof(t_data)));
	if (!data)
		exit(0);
	ft_check_input_and_format(argc, argv);
	ft_data_initialisation(data);
    ft_parser(data, argv);
	ft_print_map(data, data->map);
	ft_init_mlx(data);
	ft_open_textures(data);
	//ft_create_small_map(data);
	//printf("%lf\n",data->player.y);
	//printf("%lf\n",data->player.x);
	//ft_print_reverse_map(data, data->map);
	//printf("INITIAL DIR = %c\n", data->player.initial_direction);
	//data->player.direction = 45.0 * M_PI / 180.0;
	//data->player.cos_direction = cos(data->player.direction);
	//data->player.sin_direction = sin(data->player.direction);
	//data->player.tan_direction = tan(data->player.direction);

	//ft_print_reverse_map(data, data->map);
	//ft_black_screen(data);
	//ft_print_map_in_2d(data);
	//ft_draw_player_orientation(data);
	//mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

	// a suppriner qd map bien init
	data->player.x = 3.5;
	data->player.y = 3.5;
	data->player.direction = 0;



	mlx_hook(data->window, 2, (1L << 0), &ft_move_player, data);
	mlx_hook(data->window, 17, (1L << 17), ft_exit, data);
	mlx_loop_hook(data->mlx, &ft_handle_event, data);
	mlx_loop(data->mlx);
	return(0);
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
