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
		ft_img_pixel_put(data, x, y, COLOR_YELLOW);
		y++;
	}
}
