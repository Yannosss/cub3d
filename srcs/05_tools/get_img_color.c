#include "cub3D.h"

int	ft_get_color(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_len + x * (img->bpp / 8))));
	// etapes decomposees pour debug
	//char	*pixel;
	//int	color;

	//pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	//color = *(int *)pixel;
	//return (color);
}
