/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:17:06 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 18:40:01 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	print_hex(unsigned int n)
{
	if (n >= 16)
	{
		print_hex(n / 16);
		print_hex(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar((n - 10 + 'a'));
		else
			ft_putchar((n + '0'));
	}
	return (hex_len(n));
}

int	print_hex_caps(unsigned int n)
{
	if (n >= 16)
	{
		print_hex_caps(n / 16);
		print_hex_caps(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar((n - 10 + 'A'));
		else
			ft_putchar((n + '0'));
	}
	return (hex_len(n));
}

/*int main()
{
	int len;

	printf("print_hex = \n");
	print_hex(-17);
	printf("\nprintf = \n%x\n",-17);
	


	printf("\nprint_hex_caps = ");
	printf("\n");
	print_hex_caps(-2147483647);
	printf("\nprintf caps = \n%X\n",-2147483647);

	printf("\n");
	len = print_hex(-17);
	printf("\n");
	printf("%d",len);
	printf("\n");
	len = printf("%X",-2147483647);
	printf("\n");
	printf("%d", len);
}*/