#include "cub3D.h"

void ft_find_wall_type_impacted(t_data *data, t_ray *ray)
{
	if (ray->hit_direction == VERTICAL_WALL)
	{
		if (ray->theta_rad <= M_PI / 2 || ray->theta_rad >= 3* M_PI / 2)
		{
			ray->hit_wall_type = EAST_WALL;
		}
		else
		{
			ray->hit_wall_type = WEST_WALL;
		}
	}
	else
	{
		if (ray->theta_rad <= M_PI)
		{
			ray->hit_wall_type = SOUTH_WALL;
		}
		else
		{
			ray->hit_wall_type = NORTH_WALL;
		}
	}
}
