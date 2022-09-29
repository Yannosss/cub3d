#include "cub3D.h"

int	ft_get_texture_color(t_data *data, double percent_h_wall, t_ray *ray)
{
	int	x_texture;
	int	y_texture;
	int	color;

	if (ray->hit_wall_type == NORTH_WALL)
	{
		color = ft_get_img_color(data, &(data->textures.north_img),
				percent_h_wall, ray);
	}
	if (ray->hit_wall_type == SOUTH_WALL)
	{
		color = ft_get_img_color(data, &(data->textures.south_img),
				percent_h_wall, ray);
	}
	if (ray->hit_wall_type == EAST_WALL)
	{
		color = ft_get_img_color(data, &(data->textures.east_img),
				percent_h_wall, ray);
	}
	if (ray->hit_wall_type == WEST_WALL)
	{
		color = ft_get_img_color(data, &(data->textures.west_img),
				percent_h_wall, ray);
	}
	return (color);
}

void	ft_draw_vertical_texture_line(t_data *data, int column)
{
	double	wall_height;
	double	percent_h_wall;
	int		y_print;
	int		i;
	int		color;

	wall_height = WALL_HEIGHT_FACTOR * 1 / data->ray_tab[column].ray_len;
	i = 0;
	while (i < (int)wall_height)
	{
		percent_h_wall = (double)i / wall_height;
		y_print = WINDOW_HEIGHT / 2.0 - wall_height / 2.0 + (double)i;
		if (y_print >= 0 && y_print < WINDOW_HEIGHT)
		{
			color = ft_get_texture_color(data, percent_h_wall,
					&data->ray_tab[column]);
			ft_img_pixel_put(data, column, y_print, color);
		}
		i++;
	}
}

void	ft_print_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		ft_draw_vertical_texture_line(data, i);
		i++;
	}
}
