/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray_hit_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:19 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:20 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_point_is_on_a_vertical_wall(t_data *data, t_ray *ray, t_point pt)
{
	int	column;
	int	line;

	column = (int)round(pt.x);
	line = (int)floor(pt.y);
	if (data->map[column][line] == '1' || data->map[column - 1][line] == '1')
	{
		ray->hit_direction = VERTICAL_WALL;
		return (1);
	}
	return (0);
}

static int	ft_point_is_on_a_horizontal_wall(t_data *data, t_ray *ray,
	t_point pt)
{
	int	column;
	int	line;

	column = (int)floor(pt.x);
	line = (int)round(pt.y);
	if (data->map[column][line] == '1' || data->map[column][line - 1] == '1')
	{
		ray->hit_direction = HORIZONTAL_WALL;
		return (1);
	}
	return (0);
}

static void	ft_compute_increments(t_data *data, t_ray *ray)
{
	(void)data;
	ray->inc_l_dx = 1 / ray->cos_theta;
	ray->inc_l_dy = 1 / ray->sin_theta;
	if (ray->theta_rad > M_PI)
		ray->l_dy = (ray->start_point.y - floor(ray->start_point.y))
			/ ray->sin_theta;
	else
		ray->l_dy = (ceil(ray->start_point.y) - ray->start_point.y)
			/ ray->sin_theta;
	if (ray->theta_rad > M_PI / 2 && ray->theta_rad < 3 * M_PI / 2)
		ray->l_dx = (ray->start_point.x - floor(ray->start_point.x))
			/ ray->cos_theta;
	else
		ray->l_dx = (ceil(ray->start_point.x) - ray->start_point.x)
			/ ray->cos_theta;
	if (ray->theta_rad > M_PI)
	{
		ray->l_dy = -ray->l_dy;
		ray->inc_l_dy = -ray->inc_l_dy;
	}
	if (ray->theta_rad > M_PI / 2 && ray->theta_rad < 3 * M_PI / 2)
	{
		ray->l_dx = -ray->l_dx;
		ray->inc_l_dx = -ray->inc_l_dx;
	}
}

// take s_ray with following data already defined
// - start point
// - theta_rad
void	ft_compute_ray_hit_point(t_data *data, t_ray *ray)
{
	ft_compute_increments(data, ray);
	while (1)
	{
		if (fabs(ray->l_dx) < fabs(ray->l_dy))
		{
			ray->end_point.x = ray->start_point.x + ray->l_dx * ray->cos_theta;
			ray->end_point.y = ray->start_point.y + ray->l_dx * ray->sin_theta;
			ray->l_dx = ray->l_dx + ray->inc_l_dx;
			if (ft_point_is_on_a_vertical_wall(data, ray, ray->end_point))
				break ;
		}
		else
		{
			ray->end_point.x = ray->start_point.x + ray->l_dy * ray->cos_theta;
			ray->end_point.y = ray->start_point.y + ray->l_dy * ray->sin_theta;
			ray->l_dy = ray->l_dy + ray->inc_l_dy;
			if (ft_point_is_on_a_horizontal_wall(data, ray, ray->end_point))
				break ;
		}
	}
}
