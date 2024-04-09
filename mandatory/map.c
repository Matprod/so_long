/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:22:43 by mvoisin           #+#    #+#             */
/*   Updated: 2024/04/09 17:05:52 by mvoisin          ###   ########.fr       */
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
	while((line = get_next_line(fd)) != NULL)
	{
		nb++;
		free(line);
	}
	close(fd);
	return(nb);
}

char **fd_to_array(char *argv)
{
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
		free_array(array);
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

int get_map_height(char **map)
{
    int height;

    height = 0;
    while(*map++)
        height++;
    return(height);
}

int get_map_width(char **map)
{
    int width;

    width = 0;
    while (*(*map + width) != '\n')
        width++;
    return(width);
}

void map_len_init(t_data *data,char **map)
{
    data->height_max = 64 * get_map_height(map);
    data->width_max = 64 * get_map_width(map);
    data->height    = get_map_height(map);
    data->width     = get_map_width(map);
    //free_array(map);
}

