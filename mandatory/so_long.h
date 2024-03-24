/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:42:54 by Matprod           #+#    #+#             */
/*   Updated: 2024/03/24 18:46:58 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "../lib/mlx/mlx.h"
# include <X11/keysym.h>
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_mlx_data
{
    void	*mlx;
    void	*win;
    void	*texture[1];
    int		*img_size;
}				t_data;

/* MANDATORY FUNCTIONS*/

void	*new_window(void *mlx_connection, int height, int width, char *window_name);

void	free_everything(t_data *data);

/* IMAGES PATH */

#define GRASS_PATH "mandatory/Images/grass.xpm"


#endif