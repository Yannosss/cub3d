#include "cub3D.h"

static void	ft_open_texture_north(t_data *data)
{
	data->textures.north_img.img_pt = mlx_xpm_file_to_image (data->mlx,
	data->textures.north, &(data->textures.north_img.width),
	&(data->textures.north_img.height));
	data->textures.north_img.addr =
	mlx_get_data_addr(data->textures.north_img.img_pt,
	&(data->textures.north_img.bpp), &(data->textures.north_img.line_len),
	&(data->textures.north_img.endian));
}

static void	ft_open_texture_south(t_data *data)
{
	data->textures.south_img.img_pt = mlx_xpm_file_to_image (data->mlx,
	data->textures.south, &(data->textures.south_img.width),
	&(data->textures.south_img.height));
	data->textures.south_img.addr =
	mlx_get_data_addr(data->textures.south_img.img_pt,
	&(data->textures.south_img.bpp), &(data->textures.south_img.line_len),
	&(data->textures.south_img.endian));
}

static void	ft_open_texture_east(t_data *data)
{
	data->textures.east_img.img_pt = mlx_xpm_file_to_image (data->mlx,
	data->textures.east, &(data->textures.east_img.width),
	&(data->textures.east_img.height));
	data->textures.east_img.addr =
	mlx_get_data_addr(data->textures.east_img.img_pt,
	&(data->textures.east_img.bpp), &(data->textures.east_img.line_len),
	&(data->textures.east_img.endian));
}

static void	ft_open_texture_west(t_data *data)
{
	data->textures.west_img.img_pt = mlx_xpm_file_to_image (data->mlx,
	data->textures.west, &(data->textures.west_img.width),
	&(data->textures.west_img.height));
	data->textures.west_img.addr =
	mlx_get_data_addr(data->textures.west_img.img_pt,
	&(data->textures.west_img.bpp), &(data->textures.west_img.line_len),
	&(data->textures.north_img.endian));
}

void	ft_open_textures(t_data *data)
{
	data->textures.north = "./textures/debug_north3.xpm";
	data->textures.south = "./textures/debug_south3.xpm";
	data->textures.east = "./textures/debug_east3.xpm";
	data->textures.west = "./textures/debug_north3.xpm";

	// ajouer secu
	ft_open_texture_north(data);
	ft_open_texture_south(data);
	ft_open_texture_east(data);
	ft_open_texture_west(data);


}
