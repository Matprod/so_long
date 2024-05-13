/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:51:36 by mvoisin           #+#    #+#             */
/*   Updated: 2024/05/13 08:16:21 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_put_texture(t_data *data, char texture, int width, int height)
{
	if (texture == '1')
	{
		put_image(data, data->texture[WALL_INDEX], width * 64, height * 64);
	}
	else if (texture == '0')
	{
		put_image(data, data->texture[GRASS_INDEX], width * 64, height * 64);
	}
	else if (texture == 'P')
	{
		data->player.x = width * 64;
		data->player.y = height * 64;
		put_image(data, data->texture[ROBOT_INDEX], width * 64, height * 64);
	}
	else if (texture == 'E')
	{
		put_image(data, data->texture[WALL_INDEX2], width * 64, height * 64);
	}
	else if (texture == 'C')
	{
		put_image(data, data->texture[COIN_INDEX], width * 64, height * 64);
		data->item_total += 1;
	}
}

void	put_map_in_window(t_data *data, char **map)
{
	int	width;
	int	height;

	height = -1;
	while (++height < data->height)
	{
		width = -1;
		while (++width < data->width)
			map_put_texture(data, map[height][width], width, height);
	}
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (*map++)
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (*(*map + width) != '\n')
		width++;
	return (width);
}

void	map_len_init(t_data *data, char **map)
{
	data->h_max = 64 * get_map_height(map);
	data->width_max = 64 * get_map_width(map);
	data->height = get_map_height(map);
	data->width = get_map_width(map);
}
