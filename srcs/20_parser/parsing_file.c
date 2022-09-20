#include "cub3D.h"

/*---------------------------------------------------------
1- Check format extension : only .cub are allowed
and a file nammed ".cub" only must be consired as an error.
---------------------------------------------------------*/
void	ft_check_input_and_format(int argc, char **argv)
{
	if (argc != 2)
		ft_input_error(COLOR_RED"Error:\nWrong input: ./so_long [file.cub]"COLOR_NORMAL);
	if ((ft_strlen(argv[1]) <= 4) || (!ft_strrchr(argv[1], '.')))
		ft_input_error(COLOR_RED"Error:\nWrong file format"COLOR_NORMAL);
	if (ft_strcmp(strrchr(argv[1], '.'), ".cub") != 0)
		ft_input_error(COLOR_RED"Error:\nWrong format: file must be [.cub]"COLOR_NORMAL);
}
int	ft_skip_space(char *line)
{
	int i;

	i = 0;
	while(line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
			|| line[i] == '\n' || line[i] == '\r' || line[i] == '\f')
		i++;
	return(i);
}
/*-------------------------------------------------------------------------
		// get_texture : envoie de la string
		// j'envoie &line[index_l], etdata->texture->id 
		// je fais un split : je check si j' ai bien !str[2] 
		// Ensuite je check  je peux ouvrir str[1] : sinon error
		// si je peux : je stock str[1] dans data->texture->no
---------------------------------------------------------------------------*/
char *ft_get_texture(t_data *data, char *file)
{
	char **temp;
	char *path;
	
	printf(COLOR_MAGENTA"STRING = %s\n"COLOR_NORMAL, file);
	temp = ft_split(file, ' ');
	if (temp[2])
		ft_error_check_map(data, "error: arg after path texture");
	if (open(temp[1], O_RDONLY) < 0)
		ft_error_check_map(data, "error: can't find path");
	path = ft_malloc(data, sizeof(char *) * ft_strlen(file) + 1);
	if (!path)
		return(NULL);
	ft_strncpy(path, temp[1], ft_strlen(file));
	printf(COLOR_CYAN"FINAL : %s\n"COLOR_NORMAL, path);
	ft_free_split(temp);
 	return (path);
}

int	ft_get_floor_clr(t_data *data)
{
	return(0);
}

int ft_get_ceiling_clr(t_data *data)
{
	return(0);
}

/*
- Check if textures and colors ID are well formated : 
SO
NO
WE
EA
*/

int	ft_error_doublon(t_data *data, char *s1)
{
	if (s1)
		ft_error_check_map(data, "error: doublons in file");
	return (1);
}

int	ft_is_id_valid(t_data *data, char *line , int index_l)
{

	printf(COLOR_GREEN"%s\n"COLOR_NORMAL, &line[index_l]);
	if (ft_strncmp(&line[index_l], "NO ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.north))
			data->textures.north = ft_get_texture(data, &line[index_l]);
	}
	if (ft_strncmp(&line[index_l], "SO ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.south))
			data->textures.south = ft_get_texture(data, &line[index_l]);
	}
	if (ft_strncmp(&line[index_l], "WE ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.west))
			data->textures.west = ft_get_texture(data, &line[index_l]);
	}
	if (ft_strncmp(&line[index_l], "EA ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.east))
			data->textures.east = ft_get_texture(data, &line[index_l]);
	}
	/////////////////////////////////////////////////////////////////////
	if (ft_strncmp(&line[index_l], "F ", 2) == 0)
	{
		printf("found F\n");
		// j'envoie la string
		// split de la string avec espaces = > si tmp[2] -> error
		// split de tmp[1] avec les virgule
		// ou atoi ? 
		//get_color : mm logique : faire un atoi specifique 
	}
	if (ft_strncmp(&line[index_l], "C ", 2) == 0)
	{
		printf("found C\n");
	}
	return(0);
}

//Debug
void	ft_print_data_file(t_data *data)
{
	printf(COLOR_RED"FINAL STR NORTH: %s\n"COLOR_NORMAL, data->textures.north);
	printf(COLOR_RED"FINAL STR SOUTH: %s\n"COLOR_NORMAL, data->textures.south);
	printf(COLOR_RED"FINAL STR WEST: %s\n"COLOR_NORMAL, data->textures.west);
	printf(COLOR_RED"FINAL STR EAST: %s\n"COLOR_NORMAL, data->textures.east);
}

int	ft_parse_colums(t_data *data)
{
	int index_c;
	int index_l;

	index_c = 0;
	while (data->file_content[index_c])
	{
		index_l = ft_skip_space(data->file_content[index_c]);
		printf("INDEX = %d\n", index_l);
		ft_is_id_valid(data, data->file_content[index_c], index_l);
		index_c++;
		//printf("CHAR = %c\n", data->file_content[index_c][index_l +1]);
		if (data->file_content[index_c][index_l +1] == '1')
			break;
	}
	// retourner l'emplacement de la derniere colonne
	ft_print_data_file(data);
	return(index_c);
}

