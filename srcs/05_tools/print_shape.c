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
