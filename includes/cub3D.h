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


typedef struct s_player
{
	double x;
	double y;
	double direction;
}	t_player;

typedef struct s_data
{
    char    **map;
	int     nb_player;
	t_player	player;
    int     map_width; // for the longest line of the manp
    int     map_length; // nb of lines in the map (including empty lines) 
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
