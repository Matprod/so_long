/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:53:18 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/15 18:14:19 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool line_of_wall(char *map, int len)
{
	len--;
	while (--len >= 0)
	{
		if (map[len] != '1')
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
/* void print_tableau(char **map) {
    int i = 0;
    while (map[i] != NULL) { // Boucle jusqu'à ce qu'on atteigne la fin du tableau (NULL)
        printf("%s\n", map[i]);
        i++;
    }
} */

bool	check_size(t_data *data, char **map)
{
	int			i;
	int			first_line;

	i = -1;
	//print_tableau(map);
	first_line = ft_strlen(map[0]);
	if (!line_of_wall(map[0], first_line))
		return (FALSE);
	while (map[++i] && i < data->height - 1)
	{
		if (ft_strlen(map[i]) != first_line)
		{
			return (FALSE);
		}
		if (map[i][0] != '1' || map[i][first_line -2] != '1')
		{
			return (FALSE);
		}
	}
	if (i > 0 && !line_of_wall(map[i], first_line))
		return (FALSE);
	return (TRUE);
}