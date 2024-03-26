/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:28:41 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/26 15:12:34 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_everything(t_data *data)
{
	int i;

	i = -1;
	while(++i < 2)
	    mlx_destroy_image(data->mlx, data->texture[i]);
    mlx_destroy_image(data->mlx, data->texture[1]); 
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
}