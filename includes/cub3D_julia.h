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

//----------- errors.c ---------------------------------//
void	ft_input_error(char *msg);
void	ft_fd_error(char *msg, char *map, t_img *input);
void	ft_error_empty_map(t_img *input, char *map);

//------------------ parser.c ----------------------------//
void	ft_check_input_and_format(int argc, char **argv);
char	**ft_read_map(t_img *input, char *file);
int	ft_check_map(t_img *input, char *file);