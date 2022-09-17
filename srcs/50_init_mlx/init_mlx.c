#include "cub3D.h"

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	//if (env->mlx == NULL)
	//	ft_exit_mlx(env, "error: MLX init");
	data->window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	//if (env->window == NULL)
	//	ft_exit_mlx(env, "error: wiwndows creation");
	data->img.img_pt = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//if (env->img.img_pt == NULL)
	//	ft_exit_mlx(env, "error: image creation");
	data->img.addr = mlx_get_data_addr(img.img_pt, &(img.bpp),
			&(img.line_len), &(img.endian));
}
