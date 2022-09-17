#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include "mlx.h"
# include "libft.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

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

typedef struct s_player
{
	double x;
	double y;
	double direction;
}	t_player;

typedef struct s_image
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_colors
{
    int r;
    int g;
    int b;
    int alpha;
}	t_colors;

typedef struct s_textures
{
	char    *north;
    char    *south;
    char    *west;
    char    *east;
    t_colors    colors;
}	t_textures;

typedef struct s_data
{
	t_list	*garbage_collector;
    char    **map;
	int     nb_player;
	t_player	player;
    int     map_width; // for the longest line of the manp
    int     map_height; // nb of lines in the map (including empty lines)
	t_textures	textures;

	void	*mlx;
	void	*window;
	t_image	img;

}	t_data;

typedef struct s_img
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

# include "cub3D_julia.h"
# include "cub3D_yann.h"

#endif
