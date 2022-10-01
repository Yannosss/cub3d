/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:05:50 by ybellot           #+#    #+#             */
/*   Updated: 2022/10/01 12:05:51 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "cub3D.h"
/------------------------- DEBUG -----------------------------/
void	ft_print_file_content(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"FILE CONTENT\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (data->file_content[i])
	{
		j = 0;
		while (data->file_content[i][j])
		{
			printf("%c", content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);

}
//print the map + map's values 
void	ft_print_reverse_map(t_data *data, char **content)
{
	int i;
	int j;

	i = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"REVERSE MAP\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (i < data->map_width)
	{
		j = 0;
		while (j < data->map_height)
		{	
			if (content[i][j] == '\0')
			{
				printf(" ");
				j++;
			}
			else
				printf("%c", content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
}
/---------------------------------------------------------------/
void	ft_print_map(t_data *data, char **content)
{
	int y;
	int x;

	y = 0;
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf(COLOR_GREEN"MAP\n"COLOR_NORMAL);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (content[x][y] == '\0')
			{
				printf(" ");
				x++;
			}
			else
				printf("%c", content[x][y]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
}

void	ft_print_all(t_data *data)
{
    ft_print_map(data, data->map);
    ft_print_reverse_map(data, data->map);
	printf(COLOR_GREEN"\n------------------------------\n"COLOR_NORMAL);
	printf("WITDH = %d\n", data->map_width);
	printf("HEIGHT = %d\n", data->map_height);
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
}

*/
