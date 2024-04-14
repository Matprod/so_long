/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:54:18 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/14 17:12:08 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	var_init(t_data *data)
{
	map_len_init(data, data->map);
	data->mlx = mlx_init();
	data->win = new_window(data->mlx, data->width_max, data->height_max , "so_long"); 
    img_init(data);
    put_map_in_window(data,data->map);

	data->item_total = 0;
	data->items = 0;
	//data->player.pos = "right";
	data->player.move = 0;
	data->player.x = 48;
	data->player.y = 48;
}