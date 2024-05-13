/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:41:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/05/13 08:17:15 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2)
		return (ERROR);
	data.map = fd_to_array(argv[1]);
	if (!data.map)
		return (ERROR);
	var_init(&data);
	if (check_error(&data, data.map) == FALSE)
	{
		free_everything(&data);
		return (ERROR);
	}
	if (data.mlx == NULL)
		return (MALLOC_ERROR);
	mlx_hook(data.win, 2, 1L << 0, key_gestion, &data);
	mlx_hook(data.win, 17, 0, free_everything, &data);
	mlx_loop(data.mlx);
	return (1);
}
