/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:28:41 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/14 16:52:49 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_everything(t_data *data)
{
	int i;

	i = -1;
	while(++i < 4) //number of texture
	    mlx_destroy_image(data->mlx, data->texture[i]);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
	//free_array(data->map);
    free(data->mlx);
	exit(0);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}