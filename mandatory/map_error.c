/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:53:18 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/12 16:55:15 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool line_of_wall(char *map, int len)
{
	while (--len >= 0)
	{
		if (map[len] != '1')
			return (FALSE);
	}
	return (TRUE);
}

bool	check_size(t_data data, char **map)
{
	int			i;
	int			first_line;

	i = -1;
	first_line = data.height;
	if (!line_of_wall(map[0], first_line))
		return (FALSE);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != first_line)
			return (FALSE);
		if (map[i][0] != '1' || map[i][first_line - 1] != '1')
			return (FALSE);
	}
	if (i > 0 && !line_of_wall(map[i - 1], first_line))
		return (FALSE);
	return (TRUE);
}