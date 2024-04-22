/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_traverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:22:55 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/22 17:18:20 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_start_and_end(t_point *start, t_point *end, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				start->x = j;
				start->y = i;
			}
			else if (map[i][j] == 'E')
			{
				end->x = j;
				end->y = i;
			}
		}
	}
}
char	**dup_map(char **map)
{
	char		**dup;
	int const	height = get_map_height(map);
	int			i;

	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
			return (NULL);
	}
	dup[height] = 0;
	return (dup);
}
void	fill(t_data *data, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		data->item_fill ++;
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, x, y - 1);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, x + 1, y);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
	{
		map[y][x] = 'F';
		fill(data, map, x - 1, y);
	}
	map[y][x] = 'F';
}

int	flood_fill(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.y = 0;
	end.x = 0;

	char	**dup;

	dup = dup_map(data->map);
	if (!dup)
		return (0);
	data->item_fill = 0;
	get_start_and_end(&start, &end, dup);
	fill(data, dup, start.x, start.y);
	if (dup[end.y][end.x] == 'F' && data->item_total == data->item_fill)
	{
		free_array(dup);
		return (1);
	}
	free_array(dup);
	return (0);
}

