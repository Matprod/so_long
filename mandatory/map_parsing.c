/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:43 by mvoisin           #+#    #+#             */
/*   Updated: 2024/05/13 08:08:32 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_nb_line_fd(char *argv)
{
	int		fd;
	char	*line;
	int		nb;

	line = "a";
	nb = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb);
}

static char	*close_and_free(char **array, int fd)
{
	free_array(array);
	close(fd);
	return (NULL);
}

char	**fd_to_array(char *argv)
{
	int		fd;
	int		nb;
	char	*line;
	char	**array;

	nb = get_nb_line_fd(argv);
	if (nb == 0)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!array)
		close_and_free(array, fd);
	nb = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		array[nb++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	array[nb] = NULL;
	close(fd);
	return (array);
}
