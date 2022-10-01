#include "cub3D.h"

int	ft_is_on_wall(t_data *data, double x, double y)
{
	double	pt1[2];
	double	pt2[2];
	double	pt3[2];
	double	pt4[2];

	pt1[0] = x - HITBOX_LEN;
	pt1[1] = y - HITBOX_LEN;
	pt2[0] = x + HITBOX_LEN;
	pt2[1] = y - HITBOX_LEN;
	pt3[0] = x + HITBOX_LEN;
	pt3[1] = y + HITBOX_LEN;
	pt4[0] = x - HITBOX_LEN;
	pt4[1] = y + HITBOX_LEN;
	if (data->map[(int)floor(pt1[0])][(int)floor(pt1[1])] == '1')
		return (1);
	if (data->map[(int)floor(pt2[0])][(int)floor(pt2[1])] == '1')
		return (1);
	if (data->map[(int)floor(pt3[0])][(int)floor(pt3[1])] == '1')
		return (1);
	if (data->map[(int)floor(pt4[0])][(int)floor(pt4[1])] == '1')
		return (1);
	return (0);
}
