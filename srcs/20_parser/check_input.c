#include "cub3D.h"

// utils
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

//Check format extension
void	ft_check_input_and_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error(RED"Error:\nWrong input: ./so_long [file.cub]"NORMAL);
	if ((ft_strlen(argv[1]) <= 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error(RED"Error:\nWrong file format"NORMAL);
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error(RED"Error:\nWrong format: file must be [.cub]"NORMAL);
}
