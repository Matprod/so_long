/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:23:14 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/14 16:42:58 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_gestion(int keycode, t_data *data, char **map)
{
	if (keycode == ESC)
		free_everything(data);
	else if (keycode == W)
		move(data, "up",map);
	else if (keycode == S)
		move(data, "down",map);
	else if (keycode == A)
		move(data, "left",map);
	else if (keycode == D)
		move(data, "right",map);
	return (0);
}



void	put_current(t_data *data)
{
	int const	x = data->player.x;
	int const	y = data->player.y;

	if (data->player.current == 'E' && data->items != data->item_total)
		put_img(data, data->texture[ROBOT_INDEX], x, y);
	else if (data->player.current == 'P')
		put_img(data, data->texture[ROBOT_INDEX], x, y);
	else
		put_img(data, data->texture[GRASS_INDEX], x, y);
}

void	edit_pos(t_data *data, char *direction)
{
	if (!strcmp(direction, "up"))
		data->player.y -= 48;
	else if (!strcmp(direction, "down"))
		data->player.y += 48;
	else if (!strcmp(direction, "left"))
	{
		data->player.x -= 48;
		data->player.pos = "left";
	}
	else if (!strcmp(direction, "right"))
	{
		data->player.x += 48;
		data->player.pos = "right";
	}
}

char	get_next(char **map, t_data *data, char *direction)
{
	if (!strcmp(direction, "up"))
		return (map[data->player.y / 64 - 1][data->player.x / 64]);
	else if (!strcmp(direction, "down"))
		return (map[data->player.y / 64 + 1][data->player.x / 64]);
	else if (!strcmp(direction, "left"))
		return (map[data->player.y / 64][data->player.x / 64 - 1]);
	else
		return (map[data->player.y / 64][data->player.x / 64 + 1]);
}

void	move(t_data *data, char *direction,char ** map)
{
	char const	next = get_next(map, data, direction);
	int			x;
	int			y;

	data->player.current = map[data->player.y / 64][data->player.x / 64];
	if (next == 'E' && data->items == data->item_total)
		free_everything(data);
	if (next != '1')
	{
		ft_printf("Moves : %d\n", ++data->player.move);
		put_current(data);											
		edit_pos(data, direction);
		x = data->player.x;
		y = data->player.y;
		if (next == 'E')
			put_img(data, data->texture[ROBOT_INDEX], x, y);
		else if (next == 'P')
			put_img(data, data->texture[ROBOT_INDEX], x, y);
		else
			put_dino(data, x, y);
		if (next == 'C')
			item_collect(data);
	}
}