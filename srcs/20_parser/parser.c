#include "cub3D.h"
#include <stdlib.h>
/************** ft_parser *********************************
1- Check map extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
2- Map must be surrounded by walls :  O has to be surrounded by 0 or 1
if space is found arround 0 -> map is invalid.
3- il peut y avoir des ligne vides
4- il n'y a qu'un Player

**********************************************************/

// utils
/*
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
*/
/* Return input error and quit properly 
void	ft_input_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

//Check format extension
void	ft_check_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error("Error:\nWrong input: ./so_long [file.cub]");
	if ((ft_strlen(argv[1]) <= 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error("Error:\nWrong file format");
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error("Error:\nWrong format: file must be [.cub]");
    //temporaire
    else
        printf("Format OK\n");
}*/