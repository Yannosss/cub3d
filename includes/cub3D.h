#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>


# include "mlx.h"
# include "libft.h"

# define WINDOW_WIDTH 1024 //800 // doit etre pair
# define WINDOW_HEIGHT 768 //600
# define FOV 1.5708 // 90deg

# define MOVE_SPEED 0.1
# define ROTATION_SPEED 0.1


# define TEXTURE_WIDTH 200
# define TEXTURE_HEIGHT 200


# define NORTH_WALL 0
# define SOUTH_WALL 1
# define EAST_WALL 2
# define WEST_WALL 3

# define VERTICAL_WALL 0
# define HORIZONTAL_WALL 1



//Colors for bash
# define COLOR_NORMAL  "\x1B[0m"
# define COLOR_RED  "\x1B[31m"
# define COLOR_GREEN  "\x1B[32m"
# define COLOR_YELLOW  "\x1B[33m"
# define COLOR_BLUE  "\x1B[34m"
# define COLOR_MAGENTA  "\x1B[35m"
# define COLOR_CYAN  "\x1B[36m"
# define COLOR_WHITE  "\x1B[37m"

//Colors for mlx
# define MLX_COLOR_WHITE 0xFFFFFF
# define MLX_COLOR_RED 0xFF0000
# define MLX_COLOR_GREEN 0x00FF00
# define MLX_COLOR_BLUE 0x0000FF
# define MLX_COLOR_ORANGE 0xFF8000
# define MLX_COLOR_BLACK 0x000000


#define NORTH_WALL 0
#define SOUTH_WALL 1
#define EAST_WALL 2
#define WEST_WALL 3

typedef struct s_point
{
	double x;
	double y;
}	t_point;

typedef struct s_ray
{
	t_point	start_point;
	double	theta_rad; // radian direction est = 0 oriente de x vers y !! sens horaire sur rep ecran
	double	cos_theta;
	double	sin_theta;
	double	tan_theta;
	double	fish_eye_angle;
	t_point	end_point;
	t_point	camera_point;
	double	ray_len;
	int hit_direction;
	int	hit_wall_type;
	double	percent_w_wall; // % sur le point d'impact par rapport a la longeur du mur
	}	t_ray;

typedef struct s_player
{
	double x;
	double y;
	double direction; // radian, direction 0 = x+ = est
	double	cos_direction;
	double	sin_direction;
	double	tan_direction;
	int	pos[2];
	char initial_direction;
}	t_player;

typedef struct s_image
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;


typedef struct s_ceiling_clr
{
    int r;
    int g;
    int b;
	int	checked;
	int	color;
}	t_ceiling_clr;

typedef struct s_floor_clr
{
    int r;
    int g;
    int b;
    int	checked;
	int color;
}	t_floor_clr;

typedef struct s_img
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_textures
{
	char    *north;
	t_img	north_img;
    char    *south;
	t_img	south_img;
    char    *west;
	t_img	west_img;
    char    *east;
	t_img	east_img;
}	t_textures;

typedef struct s_data
{
	t_list	*garbage_collector;
    char    **pars_map;
	char	**map;
	char	**file_content;
	int     nb_player;
	int		id_filled;
	t_player	player;
    int     map_width; // for the longest line of the manp
    int     map_height; // nb of lines in the map (including empty lines)
	double d_camera; // (1 / 2) / tan (FOV / 2)
	t_ray	*ray_tab;

	t_textures	textures;
	t_floor_clr    floor_clr;
	t_ceiling_clr    ceiling_clr;
	int map_start;
	void	*mlx;
	void	*window;
	t_img	img;

}	t_data;



# include "cub3D_julia.h"
# include "cub3D_yann.h"

#endif
