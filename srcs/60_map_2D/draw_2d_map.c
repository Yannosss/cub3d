#include "cub3D.h"

// print 2D map without checking size
void	ft_print_map_in_2d(t_data *data)
{
	int	square_size;
	int	i;
	int	j;

	square_size = BLOCKSIZE_2D;
	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[i][j] == '1')
				ft_draw_square(data, i *square_size, j * square_size, square_size);
			i++;
		}
		j++;
	}
	ft_img_pixel_put(data, square_size * data->player.x, square_size * data->player.y, MLX_COLOR_RED);

}
