#include "cub3D.h"

void	ft_draw_square(t_data *data, int x, int y, int width)
{
	int	i;
	int	j;

	j = y;
	while (j < y + width)
	{
		i = x;
		while (i < x + width)
		{
			if (i == x || j == y | i == x + width -1 || j == y + width - 1)
				ft_img_pixel_put(data, i, j, MLX_COLOR_GREEN);
			else
				ft_img_pixel_put(data, i, j, MLX_COLOR_BLUE);
			i++;
		}
		j++;
	}
}

// draw vertical line of len 'len' centered on y = WINDOW_HEIGHT / 2
void	ft_draw_vertical_line(t_data *data, int x, int len)
{
	int	y;

	y = WINDOW_HEIGHT / 2 - len / 2;
	while (y < WINDOW_HEIGHT / 2 + len / 2)
	{
		ft_img_pixel_put(data, x, y, MLX_COLOR_GREEN);
		y++;
	}
}

void	ft_black_screen(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			ft_img_pixel_put(data, x, y, MLX_COLOR_BLACK);
			y++;
		}
		x++;
	}
}

void	ft_draw_player_orientation(t_data *data)
{
	double y;
	double x;

	y = data->player.tan_direction / sqrt(1 + pow(data->player.tan_direction, 2));
	x = y / data->player.tan_direction;
	x += data->player.x;
	y += data->player.y;
	ft_print_orange_pixel_on_2D_map(data, x, y);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);

}
