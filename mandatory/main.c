/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:41:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/24 18:40:32 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MALLOC_ERROR	1
#define WIDTH			600
#define HEIGHT			800

int	handle_input(int keysym, t_data *data)
{
    //Check the #defines
    //find / -name keysym.h 2>/dev/null
    //find / -name keysymdef.h 2>/dev/null
    if (keysym == XK_Escape)
    {
        ft_printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        exit(1);
    }
    ft_printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

int	main()
{
    t_data	data;

    data.mlx = mlx_init();
	if (data.mlx == NULL )
		return (MALLOC_ERROR);

	data.win = new_window(data.mlx, WIDTH, HEIGHT , "so_long");

	// EVENT LOOP
	mlx_key_hook(data.win, 
                handle_input, 
                &data);				
	mlx_loop(data.mlx);



	free_everything(&data);
}