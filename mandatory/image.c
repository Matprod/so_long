/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:27:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/24 18:44:31 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data data, void *image, int x, int y)
{
	mlx_put_image_to_window(data.mlx, data.win, image, x, y);
}


void	*ft_open_xpm(t_data *data, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &data->img_size,
			&data->img_size);
/* 	if (!img)
		fail_xpm(data, index); */
	return (img);
}

void	img_init(t_data *data)
{
	data->texture[0] = ft_open_xpm(data, GRASS_PATH, 0);

}