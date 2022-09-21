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

int	ft_is_valid_char(t_data *data, char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
	{
		data->nb_player++;
		return (0);
	}
	if (pos != ' ' && pos != '1' && pos != '0')
		return(ft_error_check_map(data, "error: invalid map"));
	return(0);
}