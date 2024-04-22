/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:56:23 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 18:40:56 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	print_str(char *s)
{
	int	len;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = write(1, s, ft_strlen(s));
	return (len);
}
