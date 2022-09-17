
#define BLOCKSIZE_2D


//-----------------------------------------
//               05_tools
//-----------------------------------------
// garbage collector 1
void			ft_init_garbage_collector(t_data *data);
void			*ft_malloc(t_data *data, size_t size);
void			ft_add_to_garbage_collector(t_data *data, void *content);
void			ft_free_garbage_collector(t_data *data);
// garbage collector 2
void			ft_print_garbage_collector(t_data *data);
void			ft_free(t_data *data, void *address);

//-----------------------------------------
//               10_initialisation
//-----------------------------------------
//init_mlx.c.c
