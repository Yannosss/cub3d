#include "cub3D.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_img	img;

	// initialisation mlx avec suprression des protections

	mlx = mlx_init();
	//if (env->mlx == NULL)
	//	ft_exit_mlx(env, "error: MLX init");
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	//if (env->window == NULL)
	//	ft_exit_mlx(env, "error: wiwndows creation");
	img.img_pt = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//if (env->img.img_pt == NULL)
	//	ft_exit_mlx(env, "error: image creation");
	img.addr = mlx_get_data_addr(img.img_pt, &(img.bpp),
			&(img.line_len), &(img.endian));

	while (1);

}
