#include "cub3D.h"

void	ft_img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}


//void	put_pixel_to_img(t_tex *img, int x, int y, int color)
//{
//	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
//		return ;
//	*(int *)(img->addr + ((x + y * SCREEN_WIDTH) * img->bpp)) = color;
//}
