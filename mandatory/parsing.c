/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:51:36 by mvoisin           #+#    #+#             */
/*   Updated: 2024/04/09 17:58:06 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void map_put_texture(t_data *data, char texture, int width, int height)
{
	if(texture == '1')
	{
		put_image(*data,data->texture[WALL_INDEX],width * 64, height * 64 );
	}
	else if (texture == '0')
	{
		put_image(*data,data->texture[GRASS_INDEX],width * 64, height * 64 );
	}
	else if (texture == 'P')
	{
		put_image(*data,data->texture[ROBOT_INDEX],width * 64, height * 64 );
	}
	else if (texture == 'E')
	{
		put_image(*data,data->texture[1],width * 64, height * 64 );
	}
	else if (texture == 'C')
	{
		put_image(*data,data->texture[COIN_INDEX],width * 64, height * 64 );
	}
	
}


void put_map_in_window(t_data *data, char **map)
{
	int width;
	int height;

	height = -1;
	while(++height < data->height)
	{
		width = -1;
		while(++width < data->width)
		{
			map_put_texture(data, map[height][width], width, height);
		}
	}
	free_array(map);
}