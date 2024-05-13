/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:54:18 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/13 08:16:21 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	var_init(t_data *data)
{
	map_len_init(data, data->map);
	data->item_total = 0;
	data->mlx = mlx_init();
	data->win = new_window(data->mlx, data->width_max,
			data->h_max, "so_long");
	data->player.x = 64;
	data->player.y = 64;
	img_init(data);
	put_map_in_window(data, data->map);
	data->items = 0;
	data->player.move = 0;
}
