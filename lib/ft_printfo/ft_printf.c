/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:43:00 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 21:57:44 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, char c)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += print_char(va_arg(args, int));
	else if (c == 's')
		print_len += print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		print_len += print_nbr(va_arg(args, int));
	else if (c == 'u')
		print_len += print_unsigned_nbr(va_arg(args, unsigned int));
	else if (c == 'p')
		print_len += print_ptr(va_arg(args, unsigned long));
	else if (c == 'x')
		print_len += print_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		print_len += print_hex_caps(va_arg(args, unsigned int));
	else if (c == '%')
		print_len += print_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	print_len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			print_len += check_format(args, *(str + 1));
			str++;
		}
		else
			print_len += print_char(*str);
		str++;
	}
	va_end(args);
	return (print_len);
}

/* #include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("len = %d ", ft_printf(" %x ", 0));
	return (0);
} */