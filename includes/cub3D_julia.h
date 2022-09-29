# include <stdlib.h>
# include <string.h>
# define FLOOR 1
# define CEILING 2

//-----------------------------------------
//               05_tools
//-----------------------------------------
void    ft_print_map(t_data *data, char **content);
void	ft_print_file_content(t_data *data, char **content);
void	ft_print_data_file(t_data *data);
void	ft_print_reverse_map(t_data *data, char **content);

//-----------------------------------------
//               20_parser
//-----------------------------------------
//------------------ parser.c ----------------------------//
char	**ft_read_file(t_data *data, char *file);
int     ft_get_file_content(t_data *data, char *file);
int     ft_parser(t_data *data, char **av);

//------------------ parser_file.c ----------------------------//
void    ft_check_input_and_format(int argc, char **argv);
int     ft_is_map_first(t_data *data);
int     ft_check_dir_order(t_data *data, char a, char b);
int     ft_parse_directions(t_data *data);
//------------------ parser_map.c ----------------------------//
int     ft_check_map(t_data *data);
int     ft_get_map(t_data *data);
int     ft_map_is_surrounded_by_walls(t_data *data);
//------------------ parser_utils.c ----------------------------//
int     ft_strcmp(char *s1, char *s2);
int     ft_is_valid_char(t_data *data, int i, int j);
//----------- pars_errors.c ---------------------------------//
void	ft_input_error(char *msg);
void	ft_fd_error(char *msg, char *map, t_data *input);
//-----------------------------------------
//               80_events
//-----------------------------------------
//------------------ ft_hooks_1.c ----------------------------//
int     ft_handle_event(t_data *data);
int     ft_move_player(int key, t_data *data);
void	ft_rotate_right(t_data *data);
void	ft_rotate_left(t_data *data);
//------------------ ft_hooks_2.c ----------------------------//
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_up(t_data *data);
int     ft_is_on_wall(t_data *data, double x, double y);

//debug 
void	ft_free_split_garbage_collector(t_data *data, char **split_str);
char	**ft_split_garbage_collector(t_data *data, char const *s, char c);
