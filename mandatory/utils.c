/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:03:17 by mvoisin           #+#    #+#             */
/*   Updated: 2024/04/14 19:57:07 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strcmp(char *s1, char *s2) 
{
    while (*s1 != '\0' || *s2 != '\0')
	{
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return 0;
}

void	item_collect(t_data *data)
{
	ft_printf("Item found %d/%d !\n", ++(data->items), data->item_total);
	data->map[data->player.y / 64][data->player.x / 64] = '0';
}