/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:43 by mvoisin           #+#    #+#             */
/*   Updated: 2024/03/26 18:19:02 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_line_fd(char *argv)
{
	int		fd;
	char	*line;
	int		nb;

	line = "a";
	nb = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
        return (0);
	while((line = get_next_line(fd)) != NULL)
	{
		nb++;
		free(line);
	}
	close(fd);
	return(nb);
}
char **fd_to_array(char *argv) {
    int fd;
    int nb;
    char *line;
    char **array;

    nb = get_nb_line_fd(argv);
    if (nb == 0)
        return NULL;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        return NULL;
    array = (char **)malloc(sizeof(char *) * (nb + 1));
    if (!array)
	{
        close(fd);
        return NULL;
    }
    nb = 0;
    while ((line = get_next_line(fd)) != NULL)
	{
        array[nb++] = ft_strdup(line);
        free(line);
    }
    array[nb] = NULL;
    close(fd);
    return (array);
}

