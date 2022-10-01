/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:23 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:24 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_ray_x_y(t_ray *ray, double start_x, double start_y)
{
	ray->start_point.x = start_x;
	ray->start_point.y = start_y;
}

static void	ft_set_ray_angle(t_ray *ray, double angle, double fish_eye_angle)
{
	ray->theta_rad = angle;
	ray->fish_eye_angle = fish_eye_angle;
	if (ray->theta_rad < 0)
		ray->theta_rad += 360.0 * M_PI / 180.0;
	else if (ray->theta_rad > 360.0 * M_PI / 180.0)
		ray->theta_rad -= 360.0 * M_PI / 180.0;
	ray->cos_theta = cos(ray->theta_rad);
	ray->sin_theta = sin(ray->theta_rad);
	ray->tan_theta = tan(ray->theta_rad);
}

static void	ft_fish_eye_correction(t_ray *ray)
{
	ray->ray_len = ray->ray_len * cos(ray->fish_eye_angle);
}

void	ft_compute_ray_len(t_data *data, t_ray *ray)
{
	(void)data;
	ray->ray_len = sqrt(pow((ray->start_point.x - ray->end_point.x), 2.0)
			+ pow((ray->start_point.y - ray->end_point.y), 2.0));
}

void	ft_generate_ray(t_data *data)
{
	int		i;
	double	decalage;
	double	x_dir;
	double	y_dir;
	double	angle;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		decalage = (double)i - ((double)WINDOW_WIDTH - 1.0) / 2.0;
		x_dir = data->player.cos_direction * data->d_camera
			- data->player.sin_direction * decalage;
		y_dir = data->player.sin_direction * data->d_camera
			+ data->player.cos_direction * decalage;
		angle = atan(decalage / data->d_camera);
		ft_set_ray_x_y(&(data->ray_tab[i]), data->player.x, data->player.y);
		ft_set_ray_angle(&(data->ray_tab[i]), data->player.direction + angle,
			angle);
		ft_compute_ray_hit_point(data, &data->ray_tab[i]);
		ft_compute_ray_len(data, &data->ray_tab[i]);
		ft_find_wall_type_impacted(data, &data->ray_tab[i]);
		ft_fish_eye_correction(&data->ray_tab[i]);
		i++;
	}
}
