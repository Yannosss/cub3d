# include <stdlib.h>
# include <string.h>

//Colors
# define NORMAL  "\x1B[0m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

typedef struct s_data
{
    char    **map;
    int     player;
    int     map_width; // for the longest line of the manp
    int     map_length; // nb of lines in the map (including empty lines) 
}	t_data;

//----------- errors.c ---------------------------------//
void	ft_input_error(char *msg);
void	ft_fd_error(char *msg, char *map, t_data *input);
void	ft_error_empty_map(t_data *input, char *map);
int	ft_error_check_map(t_data *input, char *msg);
//------------------ parser.c ----------------------------//
void    ft_check_input_and_format(int argc, char **argv);
char    **ft_read_map(t_data *input, char *file);
int     ft_get_map(t_data *input, char *file);
int     ft_get_map(t_data *input, char *file);
int     ft_is_valid_char(t_data *input, char pos);
int     ft_check_map(t_data *input);
int     ft_parser(t_data *input, char **av);
//------------------ DEBUG ----------------------------//
void	ft_print_map(t_data *input);