/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:27:29 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/15 17:11:22 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, image, x, y);
}

void	fail_xpm(t_data *data, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		mlx_destroy_image(data->mlx, data->texture[i]);
	//ft_printf("FAIL");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_array(data->map);
	exit(0);
}

void	*ft_open_xpm(t_data *data, char *path, int index)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &data->img_size,
			&data->img_size);
 	if (!img)
		fail_xpm(data, index); 
	return (img);
}

void	img_init(t_data *data)
{
	data->texture[0] = ft_open_xpm(data, GRASS_PATH, 0);
	data->texture[1] = ft_open_xpm(data, WALL_PATH, 1);
	data->texture[2] = ft_open_xpm(data, ROBOT_PATH, 2);
	data->texture[3] = ft_open_xpm(data, COIN_PATH, 3);
	data->texture[4] = ft_open_xpm(data, WALL2_PATH, 4);
}