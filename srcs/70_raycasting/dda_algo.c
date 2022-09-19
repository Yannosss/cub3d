#include "cub3D.h"


static int	ft_point_is_on_a_wall(t_data *data, t_point pt)
{
	// fonction a faire avec test collision
	static int i = 0;

	i++;
	if (i > 3)
		return (1);
	else
		return (0);

}

static int	ft_point_is_on_a_vertical_wall(t_data *data, t_point pt)
{
	int column;
	int line;

	column = (int)round(pt.x);
	line = (int)floor(pt.y);

	if (data->map[column][line] == '1' || data->map[column - 1][line] == '1')
	{
		return (1);
	}
	return(0);
}

static int	ft_point_is_on_a_horizontal_wall(t_data *data, t_point pt)
{
	int column;
	int line;

	column = (int)floor(pt.x);
	line = (int)round(pt.y);

	if (data->map[column][line] == '1' || data->map[column][line - 1] == '1')
	{
		return (1);
	}
	return(0);
}

// take s_ray with following data already defined
// - start point
// - theta_rad
void	ft_compute_ray_hit_point(t_data *data, t_ray *ray)
{
	double	l_dx;
	double	l_dy;
	double	inc_l_dx;
	double	inc_l_dy;

	ray->cos_theta = cos(ray->theta_rad);
	ray->sin_theta = sin(ray->theta_rad);
	ray->tan_theta = tan(ray->theta_rad);

	inc_l_dx = 1 / ray->cos_theta;
	inc_l_dy = 1 / ray->sin_theta;

	l_dx = (ceil(ray->start_point.x) - ray->start_point.x) / ray->cos_theta;
	l_dy = (ceil(ray->start_point.y) - ray->start_point.y) / ray->sin_theta;

	if (ray->theta_rad > M_PI)
	{

		inc_l_dy = -inc_l_dy;
		l_dy = -l_dy;
	}
	if (ray->theta_rad > M_PI / 2 && ray->theta_rad < 3 * M_PI / 2)
	{
		inc_l_dx = -inc_l_dx;
		l_dx = -l_dx;
	}

	while (1)
	{
		if (fabs(l_dx) < fabs(l_dy))
		{
			ray->end_point.x = ray->start_point.x + l_dx * ray->cos_theta;
			ray->end_point.y = ray->start_point.y + l_dx * ray->sin_theta;
			l_dx = l_dx + inc_l_dx;
			if (ft_point_is_on_a_vertical_wall(data, ray->end_point))
				break;
		}
		else
		{
			ray->end_point.x = ray->start_point.x + l_dy * ray->cos_theta;
			ray->end_point.y = ray->start_point.y + l_dy * ray->sin_theta;
			l_dy = l_dy + inc_l_dy;
			if (ft_point_is_on_a_horizontal_wall(data, ray->end_point))
				break;

		}
	ft_print_red_pixel_on_2D_map(data, ray->end_point.x, ray->end_point.y);
	}
	ft_print_red_pixel_on_2D_map(data, ray->end_point.x, ray->end_point.y);
	// determiner le type de mur et la zone d'impact
}

void ft_compute_ray_len(t_data *data, t_ray *ray)
{
	ray->ray_len = sqrt(pow((ray->start_point.x - ray->end_point.x), 2.0)
		 + pow((ray->start_point.y - ray->end_point.y), 2.0));
}
