/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:43 by mvoisin           #+#    #+#             */
/*   Updated: 2024/03/26 16:11:21 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *fd_to_array(char *argv)
{
	int		fd;
	char	*line;
	char	**array;
	int		nb;

	nb = 0;
	fd = open(argv, O_RDONLY);
	while(line != NULL)
	{
		line = get_next_line(fd);
		nb++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	array = (char **)malloc(sizeof(char *) * nb);
	if (!array)
		return (NULL);
	nb = -1;
	while(line != NULL)
	{
		line = get_next_line(fd);
		array[++nb] = line;
	}
	array[nb + 1] = NULL;
	close(fd);
	return(array);
}