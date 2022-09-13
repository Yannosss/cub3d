#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include "mlx.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_img
{
	void	*img_pt;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

#endif
