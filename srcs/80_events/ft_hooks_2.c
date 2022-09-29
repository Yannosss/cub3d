#include "cub3D.h"

int	ft_is_on_wall(t_data *data, double x, double y)
{
	if (data->map[(int)floor(x)][(int)floor(y)] == '1')
		return (1);
	return (0);
}

void	ft_move_up(t_data *data)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x + cos(data->player.direction) * MOVE_SPEED;
	next_y = data->player.y + sin(data->player.direction) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}

void	ft_move_down(t_data *data)
{
	double	next_x;
	double	next_y;

	next_x = data->player.x - cos(data->player.direction) * MOVE_SPEED;
	next_y = data->player.y - sin(data->player.direction) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}

void	ft_move_left(t_data *data)
{
	double	rad;
	double	next_x;
	double	next_y;

	rad = (data->player.direction) + (90 * M_PI / 180.0);
	next_x = data->player.x - cos(rad) * MOVE_SPEED;
	next_y = data->player.y - sin(rad) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}

void	ft_move_right(t_data *data)
{
	double	rad;
	double	next_x;
	double	next_y;

	rad = (data->player.direction) - (90 * M_PI / 180.0);
	next_x = data->player.x - cos(rad) * MOVE_SPEED;
	next_y = data->player.y - sin(rad) * MOVE_SPEED;
	if (!ft_is_on_wall(data, next_x, next_y))
	{
		data->player.x = next_x;
		data->player.y = next_y;
	}
}
