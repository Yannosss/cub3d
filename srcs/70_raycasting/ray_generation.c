#include "cub3D.h"

static void	ft_set_ray(t_ray *ray, double start_x, double start_y, double angle, double fish_eye_angle)
{
	ray->start_point.x = start_x;
	ray->start_point.y = start_y;
	ray->theta_rad = angle;
	ray->fish_eye_angle = fish_eye_angle;
}


static void	ft_fish_eye_correction(t_ray *ray, double angle)
{
	ray->ray_len = ray->ray_len * cos(angle);
}

void	ft_generate_ray(t_data *data)
{
	int	i;
	double	angle;
	double delta_angle;

	data->ray_tab = malloc(sizeof(t_ray) * WINDOW_WIDTH); // optimisable en prenant une CST
	angle = 0; //-FOV / 2;
	delta_angle = FOV / (WINDOW_WIDTH - 1);
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ft_set_ray(&(data->ray_tab[i]), data->player.x, data->player.x, data->player.direction + angle, angle);
		ft_compute_ray_hit_point(data, &data->ray_tab[i]);
		ft_compute_ray_len(data, &data->ray_tab[i]);
		ft_fish_eye_correction(&data->ray_tab[i], angle);
		printf("i:%d, len:%lf\n", i , data->ray_tab[i].ray_len);
		ft_draw_vertical_line(data, i, 300 * 1 / data->ray_tab[i].ray_len);


		angle = angle + delta_angle;
		i++;
	}
}


