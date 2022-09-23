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
// skip every whitespace > change for only space > 
/*		if ( || line[i] == '\t' || line[i] == '\v'
			|| line[i] == '\n' || line[i] == '\r' || line[i] == '\f')*/
int	ft_skip_space(char *line)
{
	int i;

	i = 0;
	while(line[i] && line[i] == ' ')
		i++;
	return (i);
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
	
	//printf(COLOR_MAGENTA"STRING = %s\n"COLOR_NORMAL, file);
	temp = ft_split(file, ' ');
	if (temp[2])
		ft_error_check_map(data, "error: arg after path texture");
	if (open(temp[1], O_RDONLY) < 0)
		ft_error_check_map(data, "error: can't find path");
	path = ft_malloc(data, sizeof(char *) * ft_strlen(file) + 1);
	if (!path)
		return(NULL);
	ft_strncpy(path, temp[1], ft_strlen(file));
	//printf(COLOR_CYAN"FINAL : %s\n"COLOR_NORMAL, path);
	ft_free_split(temp);
 	return (path);
}

/*
- Check str contains only digit
- Convert str to int : get nb
- 
*/
int	ft_get_nb(t_data *data, char *str)
{
	int i;
	int nb;

	i = 0;
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_check_map(data, "Error:\nColor r, b or b is not digit");
		i++;
	}
	nb = ft_atoi(str);
	if (nb > 255 || nb < 0)
		ft_error_check_map(data, "Error:\nColor r, b or b is not between 0 and 256");
	return(nb);
}

// j'envoie la string
// split de la string avec espaces = > si tmp[2] -> error
// split de tmp[1] avec les virgule
// + atoi
int	ft_get_clr(t_data *data, char *line, int type)
{
	char **tmp;

	while (*line == ' ')
		line++;
	tmp = ft_split(line, ',');
	if (!tmp)
		ft_error_check_map(data, "Error:\nMalloc allocation failed");
	if (!tmp[0] ||!tmp[1] || !tmp[2] || tmp[3])
		ft_error_check_map(data, "Error:\nWrong rgb format");
	if (type == FLOOR)
	{
		data->floor_clr.r = ft_get_nb(data, tmp[0]);
		data->floor_clr.g = ft_get_nb(data, tmp[1]);
		data->floor_clr.b = ft_get_nb(data, tmp[2]);
		data->floor_clr.checked = 1;
	}
	else if (type == CEILING)
	{
		data->ceiling_clr.r = ft_get_nb(data, tmp[0]);
		data->ceiling_clr.g = ft_get_nb(data, tmp[1]);
		data->ceiling_clr.b = ft_get_nb(data, tmp[2]);
		data->ceiling_clr.checked = 1;
	}
	ft_free_split(tmp);
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

	//printf(COLOR_GREEN"%s\n"COLOR_NORMAL, &line[index_l]);
	if (ft_strncmp(&line[index_l], "NO ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.north))
			data->textures.north = ft_get_texture(data, &line[index_l]);
	}
	else if (ft_strncmp(&line[index_l], "SO ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.south))
			data->textures.south = ft_get_texture(data, &line[index_l]);
	}
	else if (ft_strncmp(&line[index_l], "WE ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.west))
			data->textures.west = ft_get_texture(data, &line[index_l]);
	}
	else if (ft_strncmp(&line[index_l], "EA ", 3) == 0)
	{
		if (ft_error_doublon(data, data->textures.east))
			data->textures.east = ft_get_texture(data, &line[index_l]);
	}

	/////////////////////////////////////////////////////////////////////
	else if (ft_strncmp(&line[index_l], "F ", 2) == 0)
	{
		if (data->floor_clr.checked == 1)
			ft_error_check_map(data, "error: doublons of floor colors");
		ft_get_clr(data, &line[index_l + 2], FLOOR);
	}
	else if (ft_strncmp(&line[index_l], "C ", 2) == 0)
	{
		if (data->ceiling_clr.checked == 1)
			ft_error_check_map(data, "error: doublons of ceiling colors");
		ft_get_clr(data, &line[index_l + 2], CEILING);
	}
	//else
	//	ft_error_check_map(data, "error: wrong map location");
	return(0);
}


int	ft_parse_directions(t_data *data)
{
	int index_c;
	int index_l;

	index_c = 0;
	index_l = 0;
	while (data->file_content[index_c])
	{
		printf("STR = %s\n", data->file_content[index_c]);
	//	index_l = ft_skip_space(data->file_content[index_c]);
	//	printf("INDEX = %d\n", index_l);
		//ft_is_id_valid(data, data->file_content[index_c], index_l);
		index_c++;
	//	printf("ELEM = %c\n",data->file_content[index_c][index_l]);
		//if (data->file_content[index_c][index_l] == '1')
		if (data->file_content[index_c][index_l] == '0')
			break;
	}
	return(index_c);
}


/*----------------------------  Debug  ----------------------------------------*/
void	ft_print_data_file(t_data *data)
{
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_CYAN"DEBUT MAP COLONNE N: %d\n"COLOR_NORMAL, data->map_start);
	ft_print_map(data, data->map);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_RED"TEXTURE NORTH: %s\n"COLOR_NORMAL, data->textures.north);
	printf(COLOR_RED"TEXTURE SOUTH: %s\n"COLOR_NORMAL, data->textures.south);
	printf(COLOR_RED"TEXTURE WEST: %s\n"COLOR_NORMAL, data->textures.west);
	printf(COLOR_RED"TEXTURE EAST: %s\n"COLOR_NORMAL, data->textures.west);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_YELLOW"FLOOR R: %d\n"COLOR_NORMAL, data->floor_clr.r);
	printf(COLOR_YELLOW"FLOOR G : %d\n"COLOR_NORMAL, data->floor_clr.g);
	printf(COLOR_YELLOW"FLOOR B: %d\n"COLOR_NORMAL, data->floor_clr.b);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_YELLOW"CEILING R: %d\n"COLOR_NORMAL, data->ceiling_clr.r);
	printf(COLOR_YELLOW"CEILING G: %d\n"COLOR_NORMAL, data->ceiling_clr.g);
	printf(COLOR_YELLOW"CEILING B: %d\n"COLOR_NORMAL, data->ceiling_clr.b);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_MAGENTA"PLAYER POSITION: X = %d || Y = %d\n"COLOR_NORMAL, 
		data->player.pos[0],data->player.pos[1]);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);

}