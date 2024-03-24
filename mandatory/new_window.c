/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:04:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/24 16:01:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*new window:
*	Create a new window pointer using the ""
*/
void *new_window(void *mlx_connection, int height, int width, char *window_name)
{
	void *mlx_window;

	mlx_window = mlx_new_window(mlx_connection, height, width, window_name);
	if (NULL == mlx_window)
	{
		mlx_destroy_display(mlx_connection); // Cleanup MLX connection
		free(mlx_connection);
		return (0);
	}
	return(mlx_window);
}
