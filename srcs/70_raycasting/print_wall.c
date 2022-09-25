#include "cub3D.h"

//static int	get_color(t_cub3d *cub3d, float x, float y)
//{
//	if (x < 0 || x >= cub3d->map_struct.width || y < 0
//		|| y >= cub3d->map_struct.height)
//		return (MINIMAP_OUTMAP_COLOR);
//	if (cub3d->map_struct.map_strs[(int)y][(int)x] == '1')
//		return (MINIMAP_WALL_COLOR);
//	else if (cub3d->map_struct.map_strs[(int)y][(int)x] == '0')
//		return (MINIMAP_FLOOR_COLOR);
//	else
//		return (MINIMAP_OUTMAP_COLOR);
//}


int ft_get_texture_color(t_data *data, double percent_h_wall, t_ray *ray)
{
	//int width;
	//int heigth;
	//void *img;
	int x_texture;
	int	y_texture;
	int color;
	// remonter cette ligne hors de la boucle
	//img  = mlx_xpm_file_to_image (data->mlx, "./textures/debug_north.xpm", &width, &heigth);

	//if (x_texture<0) // a sup
	//	x_texture = 1; // a sup
	//printf("xtexture:%d, ytexture:%d, color:%d\n", x_texture , y_texture ,color);
	if (ray->hit_wall_type == NORTH_WALL)
	{
		x_texture = (int)(ray->percent_w_wall * data->textures.north_img.width);
		y_texture = (int)(percent_h_wall * data->textures.north_img.height);
		color = ft_get_color(&(data->textures.north_img), x_texture, y_texture);
	}
	if (ray->hit_wall_type == SOUTH_WALL)
	{
		x_texture = (int)(ray->percent_w_wall * data->textures.south_img.width);
		y_texture = (int)(percent_h_wall * data->textures.south_img.height);
		color = ft_get_color(&(data->textures.south_img), x_texture, y_texture);
	}
	if (ray->hit_wall_type == EAST_WALL)
	{
		x_texture = (int)(ray->percent_w_wall * data->textures.east_img.width);
		y_texture = (int)(percent_h_wall * data->textures.east_img.height);
		color = ft_get_color(&(data->textures.east_img), x_texture, y_texture);
	}
	if (ray->hit_wall_type == WEST_WALL)
	{

		x_texture = (int)(ray->percent_w_wall * data->textures.west_img.width);
		y_texture = (int)(percent_h_wall * data->textures.west_img.height);
		color = ft_get_color(&(data->textures.west_img), x_texture, y_texture);
	}
	//ft_img_pixel_put(data, x, y, color);
	return (color);


//	texture[0].addr = (int *)mlx_get_data_addr(texture[0].img, &texture[0].bits_per_pixel, &texture[0].line_length, &texture[0].endian);
//data.addr[y * recup->data.line_length / 4 + x] = texture[0].addr[texy * texture[0].line_length / 4 + texx];
}


void	ft_draw_vertical_texture_line(t_data *data, int column)
{
	double	wall_height;
	double	percent_h_wall;
	int	y_print;
	int	i;
	int	color;

	wall_height = WALL_HEIGHT_FACTOR * 1 / data->ray_tab[column].ray_len;
	i = 0;
	while (i < (int)wall_height)
	{
		percent_h_wall = (double)i / wall_height;
		y_print = WINDOW_HEIGHT / 2.0 - wall_height / 2.0 + (double)i;
		if (y_print >=0 && y_print < WINDOW_HEIGHT)
		{
			color = ft_get_texture_color(data, percent_h_wall, &data->ray_tab[column]);
			ft_img_pixel_put(data, column, y_print, color);
		}
		i++;
	}
	//usleep(2000);
	//mlx_put_image_to_window(data->mlx, data->window, data->img.img_pt, 0, 0);


}



void	ft_print_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		//ft_draw_vertical_line(data, i, 300 * 1 / data->ray_tab[i].ray_len, data->ray_tab[i].hit_wall_type);
		ft_draw_vertical_texture_line(data, i);
		i++;
	}
}

