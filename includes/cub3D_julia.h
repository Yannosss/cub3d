# include <stdlib.h>
# include <string.h>

//----------- errors.c ---------------------------------//
void	ft_input_error(char *msg);
void	ft_fd_error(char *msg, char *map, t_data *input);
void	ft_error_empty_map(t_data *data, char *map);
int     ft_error_check_map(t_data *data, char *msg);

//------------------ parser.c ----------------------------//
char	**ft_read_file(t_data *data, char *file);
int     ft_get_file_content(t_data *data, char *file);
int     ft_parser(t_data *data, char **av);

//------------------ parser_file.c ----------------------------//
void    ft_check_input_and_format(int argc, char **argv);
int     ft_is_map_first(t_data *data);
int     ft_check_dir_order(t_data *data, char a, char b);
int	    ft_parse_colums(t_data *data);
//------------------ parser_map.c ----------------------------//
int     ft_check_map(t_data *data);
int	ft_get_map(t_data *data);
int     ft_map_is_surrounded_by_walls(t_data *data, int pos_y, int pos_x);
//------------------ parser_utils.c ----------------------------//
int     ft_strcmp(char *s1, char *s2);
int     ft_is_valid_char(t_data *data, char pos);

//------------------ 05_tools----------------------------//
void	ft_print_map(t_data *data, char **content);