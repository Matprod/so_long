/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:41:31 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/26 16:16:35 by mvoisin          ###   ########.fr       */
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
        free_everything(&data);
        exit(1);
    }
    ft_printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

int	main(int argc, char **argv)
{
    t_data	data;

/*     if(argc != 1)
        return(NULL); */
    data.mlx = mlx_init();
	if (data.mlx == NULL )
		return (MALLOC_ERROR);

	data.win = new_window(data.mlx, WIDTH, HEIGHT , "so_long");
    
    img_init(&data);
    put_image(data,data.texture[0],0,1);
    put_image(data,data.texture[1],63,1);  	
	// EVENT LOOP
	mlx_loop(data.mlx);
 	mlx_key_hook(data.win, handle_input, &data);	 		
}