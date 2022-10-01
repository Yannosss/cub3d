/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_ray_impact.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:06:24 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:06:25 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_define_wall_impact(t_ray *ray, int hit_wall_type,
	double percent_w_wall)
{
	ray->hit_wall_type = hit_wall_type;
	ray->percent_w_wall = percent_w_wall;
}

void	ft_find_wall_type_impacted(t_data *data, t_ray *ray)
{
	(void)data;
	if (ray->hit_direction == VERTICAL_WALL)
	{
		if (ray->theta_rad <= M_PI / 2 || ray->theta_rad >= 3 * M_PI / 2)
			ft_define_wall_impact(ray, EAST_WALL, ray->end_point.y
				- floor(ray->end_point.y));
		else
			ft_define_wall_impact(ray, WEST_WALL, ceil(ray->end_point.y)
				- ray->end_point.y);
	}
	else
	{
		if (ray->theta_rad <= M_PI)
			ft_define_wall_impact(ray, SOUTH_WALL, ceil(ray->end_point.x)
				- ray->end_point.x);
		else
			ft_define_wall_impact(ray, NORTH_WALL, ray->end_point.x
				- floor(ray->end_point.x));
	}
}
