# include <stdlib.h>
# include <string.h>

/*typedef struct s_colors
{
    int r;
    int g;
    int b;
    int alpha;
}	t_colors;

typedef struct s_textures
{
	char    *north;
    char    *south;
    char    *west;
    char    *east;
    t_colors    colors;
}	t_textures;*/

//----------- errors.c ---------------------------------//
void	ft_input_error(char *msg);
void	ft_fd_error(char *msg, char *map, t_data *input);
void	ft_error_empty_map(t_data *input, char *map);
int     ft_error_check_map(t_data *input, char *msg);

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