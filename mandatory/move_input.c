/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:23:14 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/13 08:16:21 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_gestion(int keycode, t_data *data)
{
	if (keycode == ESC)
		free_everything(data);
	else if (keycode == W)
		move(data, "up");
	else if (keycode == S)
		move(data, "down");
	else if (keycode == A)
		move(data, "left");
	else if (keycode == D)
		move(data, "right");
	return (0);
}

void	put_current(t_data *data)
{
	int const	x = data->player.x;
	int const	y = data->player.y;

	if (data->player.curr == 'E' && data->items != data->item_total)
		put_image(data, data->texture[WALL_INDEX2], x, y);
	else if (data->player.curr == 'P')
		put_image(data, data->texture[GRASS_INDEX], x, y);
	else
		put_image(data, data->texture[GRASS_INDEX], x, y);
}

void	edit_pos(t_data *data, char *direction)
{
	if (!ft_strcmp(direction, "up"))
		data->player.y -= 64;
	else if (!ft_strcmp(direction, "down"))
		data->player.y += 64;
	else if (!ft_strcmp(direction, "left"))
	{
		data->player.x -= 64;
	}
	else if (!ft_strcmp(direction, "right"))
	{
		data->player.x += 64;
	}
}

char	get_next(t_data *data, char *direction)
{
	if (!ft_strcmp(direction, "up"))
		return (data->map[data->player.y / 64 - 1][data->player.x / 64]);
	else if (!ft_strcmp(direction, "down"))
		return (data->map[data->player.y / 64 + 1][data->player.x / 64]);
	else if (!ft_strcmp(direction, "left"))
		return (data->map[data->player.y / 64][data->player.x / 64 - 1]);
	else
		return (data->map[data->player.y / 64][data->player.x / 64 + 1]);
}

void	move(t_data *data, char *direction)
{
	char const	next = get_next(data, direction);
	int			x;
	int			y;

	if (!(data->player.y / 64 > data->width_max || data->player.y / 64 < 0
			|| data->player.x / 64 > data->h_max || data->player.x / 64 < 0))
	{
		data->player.curr = data->map[data->player.y / 64][data->player.x / 64];
		if (next == 'E' && data->items == data->item_total)
			free_everything(data);
		if (next != '1')
		{
			ft_printf("Moves : %d\n", ++data->player.move);
			put_current(data);
			edit_pos(data, direction);
			x = data->player.x;
			y = data->player.y;
			put_image_move(data, next, x, y);
		}
	}
}
