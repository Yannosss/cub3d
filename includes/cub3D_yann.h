
#define BLOCKSIZE_2D


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

//-----------------------------------------
//               10_initialisation
//-----------------------------------------
//init_mlx.c.c

//-----------------------------------------
//           50_exit functions
//-----------------------------------------
// exit.c
void			ft_exit(t_data *data);
