
#define BLOCKSIZE_2D 160



//-----------------------------------------
//               05_tools
//-----------------------------------------
// garbage_collector_1.c
void			ft_init_garbage_collector(t_data *data);
void			*ft_malloc(t_data *data, size_t size);
void			ft_add_to_garbage_collector(t_data *data, void *content);
void			ft_free_garbage_collector(t_data *data);
// garbagec_collector_2.c
void			ft_print_garbage_collector(t_data *data);
void			ft_free(t_data *data, void *address);
// print_color.c
void			ft_print_color(char *str);
// print_pixel.c
void	ft_img_pixel_put(t_data *data, int x, int y, int color);
// print_shape.c
void	ft_draw_square(t_data *data, int x, int y, int width);


//-----------------------------------------
//               10_initialisation
//-----------------------------------------
//data_initialisation.c
void	ft_data_initialisation(t_data *data);

//-----------------------------------------
//               50_init_mlx
//-----------------------------------------
//init_mlx.c
void	ft_init_mlx(t_data *data);

//-----------------------------------------
//               60_map_2D
//-----------------------------------------
// draw_2d_map.c
void	ft_print_map_in_2d(t_data *data);
void	ft_print_red_pixel_on_2D_map(t_data *data, double x, double y);

//-----------------------------------------
//               70_raycasting
//-----------------------------------------
// dda_algo.c
void	ft_compute_ray_hit_point(t_data *data, t_ray *ray);

//-----------------------------------------
//           90_exit functions
//-----------------------------------------
// exit.c
void			ft_exit(t_data *data);
