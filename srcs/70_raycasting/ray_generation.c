#include "cub3D.h"

static void	ft_set_ray(t_ray *ray, double start_x, double start_y, double angle, double fish_eye_angle)
{
	ray->start_point.x = start_x;
	ray->start_point.y = start_y;
	ray->theta_rad = angle;
	ray->fish_eye_angle = fish_eye_angle;
	if (ray->theta_rad < 0)
		ray->theta_rad += 360.0 * M_PI / 180.0;
	else if(ray->theta_rad > 360.0 * M_PI / 180.0)
		ray->theta_rad -= 360.0 * M_PI / 180.0;
	//printf("angle: %f\n", ray->theta_rad);

}


static void	ft_fish_eye_correction(t_ray *ray)
{
	ray->ray_len = ray->ray_len * cos(ray->fish_eye_angle); // 0.85 pour corriger fisheye a cause du raytracing angulaire
}

void	ft_generate_ray(t_data *data)
{
	//printf("direction player: %lf\n", data->player.direction * 180.0 / M_PI);
	(data);
	data->ray_tab = malloc(sizeof(t_ray) * WINDOW_WIDTH);
	int	i;
	double decalage;
	double x_dir;
	double y_dir;
	double	angle;
	//printf("#############################\n");
	//printf("direction player: %lf\n", data->player.direction * 180 / 3.14);
	//printf("#############################\n");
	//usleep(2000000);


	i = 0;
	while (i < WINDOW_WIDTH)
	{
		decalage = (double)i - ((double)WINDOW_WIDTH - 1.0) / 2.0;
		//printf("decalage: %lf\n", decalage);
		x_dir = data->player.cos_direction * data->d_camera - data->player.sin_direction * decalage;
		y_dir = data->player.sin_direction * data->d_camera + data->player.cos_direction * decalage;
		//angle = atan(y_dir / x_dir);
		angle = atan(decalage / data->d_camera);

		//printf("angle: %lf\n", angle);
		//printf("angle + player dir: %lf\n", data->player.direction + angle);
		ft_set_ray(&(data->ray_tab[i]), data->player.x, data->player.y, data->player.direction + angle, angle);
		//printf("angle ray: %lf\n", data->ray_tab[i].theta_rad);

		ft_compute_ray_hit_point(data, &data->ray_tab[i]);
		ft_compute_ray_len(data, &data->ray_tab[i]);
		ft_find_wall_type_impacted(data, &data->ray_tab[i]);
		ft_fish_eye_correction(&data->ray_tab[i]);
		ft_draw_vertical_line(data, i, 300 * 1 / data->ray_tab[i].ray_len, data->ray_tab[i].hit_wall_type);


		i++;
	}

}


//void	ft_generate_ray_old(t_data *data)
//{
//	int	i;
//	double	angle;
//	double	angle2;

//	double delta_angle;
//	double x_dir;
//	double y_dir;
//	double decalage;

//	data->ray_tab = malloc(sizeof(t_ray) * WINDOW_WIDTH); // optimisable en prenant une CST
//	angle = -FOV / 2;
//	delta_angle = FOV / (WINDOW_WIDTH - 1);
//	i = 0;
//	while (i < WINDOW_WIDTH)
//	{
//		decalage = (i - (WINDOW_WIDTH - 1)/2);
//		x_dir = data->player.cos_direction * data->d_camera - data->player.sin_direction * decalage * 1 / WINDOW_WIDTH;
//		y_dir = data->player.sin_direction * data->d_camera + data->player.cos_direction * decalage * 1 / WINDOW_WIDTH;
//		angle2 = atan(y_dir / x_dir);
//		ft_set_ray(&(data->ray_tab[i]), data->player.x, data->player.y, data->player.direction + angle2, angle2);
//		ft_compute_ray_hit_point(data, &data->ray_tab[i]);
//		ft_compute_ray_len(data, &data->ray_tab[i]);
//		ft_fish_eye_correction(&data->ray_tab[i]); // - FOV / 2);
//		//printf("i:%d, len:%lf\n", i , data->ray_tab[i].ray_len);
//		ft_draw_vertical_line(data, i, 300 * 1 / data->ray_tab[i].ray_len);


//		angle = angle + delta_angle;
//		i++;
//	}
//}


