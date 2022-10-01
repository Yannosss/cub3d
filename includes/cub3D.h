/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatoro <jbatoro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:09:04 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 18:59:48 by jbatoro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <math.h>
# include <string.h>

# include "mlx.h"
# include "libft.h"

# define WINDOW_WIDTH 1024 //1024 //800 // doit etre pair
# define WINDOW_HEIGHT 768//768 //600
# define FOV 1.5708 // 90deg

# define MOVE_SPEED 0.04
# define ROTATION_SPEED 0.05

# define NORTH_WALL 0
# define SOUTH_WALL 1
# define EAST_WALL 2
# define WEST_WALL 3

# define FLOOR 1
# define CEILING 2

# define VERTICAL_WALL 0
# define HORIZONTAL_WALL 1

# define HITBOX_LEN 0.05

# define BLOCKSIZE_2D 20
# define WALL_HEIGHT_FACTOR 300

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

# define NORTH_WALL 0
# define SOUTH_WALL 1
# define EAST_WALL 2
# define WEST_WALL 3

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// theta_rad : oriente de x vers y !! sens horaire sur rep ecran, est = 0
// % sur le point d'impact par rapport a la longeur du mur
typedef struct s_ray
{
	t_point	start_point;
	double	theta_rad;
	double	cos_theta;
	double	sin_theta;
	double	tan_theta;
	double	fish_eye_angle;
	double	l_dx;
	double	l_dy;
	double	inc_l_dx;
	double	inc_l_dy;
	t_point	end_point;
	t_point	camera_point;
	double	ray_len;
	int		hit_direction;
	int		hit_wall_type;
	double	percent_w_wall;
}	t_ray;

// direction // radian, direction 0 = x+ = est
typedef struct s_player
{
	double	x;
	double	y;
	double	direction;
	double	cos_direction;
	double	sin_direction;
	double	tan_direction;
	double	is_moving_foward;
	double	is_moving_backward;
	double	is_moving_right;
	double	is_moving_left;
	double	is_rotating_right;
	double	is_rotating_left;

}	t_player;

typedef struct s_ceiling_clr
{
	int	r;
	int	g;
	int	b;
	int	checked;
	int	color;
}	t_ceiling_clr;

typedef struct s_floor_clr
{
	int	r;
	int	g;
	int	b;
	int	checked;
	int	color;
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
	char	*north;
	t_img	north_img;
	char	*south;
	t_img	south_img;
	char	*west;
	t_img	west_img;
	char	*east;
	t_img	east_img;
}	t_textures;

typedef struct s_data
{
	t_list			*garbage_collector;
	char			**map;
	char			**file_content;
	int				nb_player;
	int				id_filled;
	t_player		player;
	int				map_width;
	int				map_height;
	double			d_camera;
	t_ray			ray_tab[WINDOW_WIDTH];
	t_textures		textures;
	t_floor_clr		floor_clr;
	t_ceiling_clr	ceiling_clr;
	int				map_start;
	void			*mlx;
	void			*window;
	t_img			img;
}	t_data;

//-----------------------------------------
//               05_tools
//-----------------------------------------
//ft_split_with_garbage_collector.c
void		ft_free_split_garbage_collector(t_data *data, char **split_str);
char		**ft_split_garbage_collector(t_data *data, char const *s, char c);
// garbage_collector_1.c
void		ft_init_garbage_collector(t_data *data);
void		*ft_malloc(t_data *data, size_t size);
void		ft_add_to_garbage_collector(t_data *data, void *content);
void		ft_free_garbage_collector(t_data *data);
// garbagec_collector_2.c
void		ft_print_garbage_collector(t_data *data);
void		ft_free(t_data *data, void *address);
//get_img_color.c
//int	ft_get_color(t_img *img, int x, int y);
int			ft_get_img_color(t_data *data, t_img *img,
				double percent_h_wall, t_ray *ray);
// print_color.c
void		ft_print_color(char *str);
// print_pixel.c
void		ft_img_pixel_put(t_data *data, int x, int y, int color);
// print_shape.c
void		ft_draw_square(t_data *data, int x, int y, int width);
void		ft_draw_vertical_line(t_data *data, int x, int len,
				int wall_Type);
void		ft_print_background(t_data *data);
void		ft_black_screen(t_data *data);
void		ft_draw_player_orientation(t_data *data);
// print_map.c
void		ft_print_map(t_data *data, char **content);
void		ft_print_file_content(t_data *data, char **content);
void		ft_print_data_file(t_data *data);
void		ft_print_reverse_map(t_data *data, char **content);

//-----------------------------------------
//               10_initialisation
//-----------------------------------------
//data_initialisation.c
void		ft_data_initialisation(t_data *data);

//-----------------------------------------
//               20_parser
//-----------------------------------------
//pars_errors.c
void		ft_input_error(char *msg);
void		ft_fd_error(char *msg, char *file, t_data *data);

//pars_file_utils_1.c
int			ft_get_nb(t_data *data, char *str);
int			ft_rgb_to_int(int r, int g, int b);
int			ft_are_id_filled(t_data *data);
int			ft_is_empty_line(char *line);
int			ft_skip_space(char *line);

//pars_file_utils_2.c
void		ft_get_floor_clr(t_data *data, char **rgb);
void		ft_get_ceil_clr(t_data *data, char **rgb);

//pars_file.c
void		ft_check_input_and_format(int argc, char **argv);
char		*ft_get_texture(t_data *data, char *file);
int			ft_get_clr(t_data *data, char *line, int type);
int			ft_is_id_valid(t_data *data, char *line, int index_l);
int			ft_parse_directions(t_data *data);

//pars_map_utils_1.c
int			ft_check_borders(t_data *data);
int			ft_check_player(t_data *data);
int			ft_check_column(t_data *data, int i, int j);
int			ft_is_valid_pos(char c);
int			ft_is_valid_char(char pos);

//pars_map_utils_2.c
int			ft_error_doublon(t_data *data, char *s1);
void		ft_malloc_map(t_data *data);
int			ft_map_is_surrounded_by_walls(t_data *data);
int			ft_check_map_is_closed(t_data *data);

//pars_map_utils_3.c
int			ft_check_one_line(t_data *data, char *line);
int			ft_is_player(char pos);
int			ft_strcmp(char *s1, char *s2);
double		ft_get_angle_from_cardinal(char c);

//pars_map.c
void		ft_get_map_size(t_data *data);
int			ft_check_map_content(t_data *data);
int			ft_fill_map(t_data *data);
int			ft_get_map(t_data *data);

//parser.c
int			ft_parser(t_data *data, char **av);

//-----------------------------------------
//               30_open_textures
//-----------------------------------------
// open_textures.c
void		ft_open_textures(t_data *data);

//-----------------------------------------
//               50_init_mlx
//-----------------------------------------
//init_mlx.c
void		ft_init_mlx(t_data *data);

//-----------------------------------------
//               60_map_2D
//-----------------------------------------
// draw_2d_map.c
void		ft_print_map_in_2d(t_data *data);
void		ft_print_red_pixel_on_2d_map(t_data *data, double x, double y);
void		ft_print_orange_pixel_on_2d_map(t_data *data, double x,
				double y);

//-----------------------------------------
//               70_raycasting
//-----------------------------------------
// dda_algo.c
void		ft_compute_ray_hit_point(t_data *data, t_ray *ray);
void		ft_compute_ray_len(t_data *data, t_ray *ray);
//image_generation.c
void		ft_generate_3d_word_image(t_data *data);
//print_wall.c
void		ft_print_wall(t_data *data);
//ray_generation.c
void		ft_generate_ray(t_data *data);
//wall_ray_impact.c
void		ft_find_wall_type_impacted(t_data *data, t_ray *ray);

//-----------------------------------------
//               80_events
//-----------------------------------------
//ft_hit_box.c
int			ft_is_on_wall(t_data *data, double x, double y);

//ft_hooks.c
int			ft_move_player_press(int key, t_data *data);
int			ft_move_player_release(int key, t_data *data);
void		ft_move(t_data *data);
int			ft_handle_event(t_data *data);

//ft_move_rotate.c
void		ft_rotate_left(t_data *data);
void		ft_rotate_right(t_data *data);

//ft_move_walk.c
void		ft_move_forward(t_data *data);
void		ft_move_backward(t_data *data);
void		ft_move_left(t_data *data);
void		ft_move_right(t_data *data);

//-----------------------------------------
//           90_exit functions
//-----------------------------------------
// exit.c
void		ft_error_exit(t_data *data, char *error_msg);
int			ft_exit(t_data *data);

//-----------------------------------------
//           pour debug
//-----------------------------------------
//static void	ft_create_small_map(t_data *data);
//static void	ft_read_map_light(t_data *data, char **argv);
//static void	ft_create_ray(t_data *data, t_ray *ray);
//void		ft_increment_player_direction(t_data *data, double inc);
//void		ft_print_all(t_data *data);

#endif
