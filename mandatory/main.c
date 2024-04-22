/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:41:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/22 17:20:10 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	handle_input(int keysym, t_data *data)
{
    //Check the #defines
    //find / -name keysym.h 2>/dev/null
    //find / -name keysymdef.h 2>/dev/null
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
		free_everything(data);
        exit(0);
    }
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

int	main(int argc, char **argv)
{
    t_data	data;

    if(argc > 2)
        return(ERROR); 
    data.map = fd_to_array(argv[1]);
    if(!data.map)
        return(ERROR);
    var_init(&data);
    if(check_error(&data, data.map) == FALSE)
    {
        free_everything(&data);
        return(ERROR);
    }
    if (data.mlx == NULL)
		return (MALLOC_ERROR);

    mlx_hook(data.win, 2, 1L << 0, key_gestion, &data);
    mlx_hook(data.win, 17, 0, free_everything, &data);
	mlx_loop(data.mlx);
    //free_array(data.map);
	
    return(1);	
}