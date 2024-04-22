/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:53:18 by Matprod           #+#    #+#             */
/*   Updated: 2024/04/22 17:18:31 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool line_of_wall(char *map, int len)
{
	len--;
	while (--len >= 0)
	{
		if (map[len] != '1')
			return (FALSE);
	}
	return (TRUE);
}

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
			return (FALSE);
		if (map[i][0] != '1' || map[i][first_line -2] != '1')
			return (FALSE);
	}
	if (i > 0 && !line_of_wall(map[i], first_line))
		return (FALSE);
	return (TRUE);
}

bool check_exit(char **map)
{
	int i;
	int number_of_exit;
	int j;

	number_of_exit = 0;
	bool exit = FALSE;
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == 'E')
				number_of_exit++;
		}
	}
	if(number_of_exit == 1)
		exit = TRUE;
	else
		exit = FALSE;
	return (exit);
}

bool check_player(char **map)
{
	int i;
	int number_of_player;
	int j;

	number_of_player = 0;
	bool exit = FALSE;
	i = -1;
	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] == 'P')
				number_of_player++;
		}
	}
	if(number_of_player == 1)
		exit = TRUE;
	else
		exit = FALSE;
	return (exit);
}

bool check_error(t_data *data, char **map)
{
	if(!check_player(map))
	{
		ft_printf("ERROR : Too much or less player\n");
		return (FALSE);
	}
	if(!check_exit(map))
	{
		ft_printf("ERROR : Too much or less exit\n");
		return (FALSE);
	}
	if(!check_size(data, map))
	{
		ft_printf("ERROR : Problem with size or walls around the map\n");
		return (FALSE);
	}
	if(!flood_fill(data))
	{
		ft_printf("ERROR : Players can't reach every collectibles or the exit\n");
		return (FALSE);
	}
	return(TRUE);

}

	
