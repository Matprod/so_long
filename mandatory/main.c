/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:41:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/09 16:57:37 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define MALLOC_ERROR	1


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
    int     i;

    i = 0;
    //INIT MAP
    if(argc > 2)
        return(0); 
    char **map;
	
    map = fd_to_array(argv[1]);

    if(!map)
        return(ft_printf("error\n"));
    while(map[i])
    {
        ft_printf("map = %s",map[i]);
        i++;
    }
    map_len_init(&data, map);
    ft_printf("\nheight = %d || width = %d || height_max = %d || width max = %d \n",data.height,data.width, data.height_max, data.width_max); 

    // INIT CONNECTION

    data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MALLOC_ERROR);

	data.win = new_window(data.mlx, data.width_max, data.height_max , "so_long"); 

    // INIT IMAGE

    img_init(&data);
    put_map_in_window(&data,map);

	// EVENT LOOP
 	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);

    // FREE 
    free_array(map);
	
    return(1);	
}