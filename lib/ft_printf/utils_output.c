/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:50:11 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 21:58:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s++)
	{
		count++;
	}
	return (count);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	print_percent(void)
{
	ft_putchar('%');
	return (1);
}
/*int	main()
{
	//ft_putnbr(-10000);
	//printf("%d",nbr_len(0));
	//ft_putstr("salut");
	return (0);
}*/