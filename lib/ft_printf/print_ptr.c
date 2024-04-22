/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:36:35 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 17:43:56 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int	ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	put_ptr(unsigned long ptr)
{
	if (ptr >= 16)
	{
		put_ptr(ptr / 16);
		put_ptr(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			ft_putchar((ptr - 10 + 'a'));
		else
			ft_putchar((ptr + '0'));
	}
}

int	print_ptr(unsigned long ptr)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
	{
		print_len = write(1, "(nil)", 5);
		return (print_len);
	}
	else
		print_len = write(1, "0x", 2);
	put_ptr(ptr);
	print_len += ptr_len(ptr);
	return (print_len);
}

/*int	main()
{
	//int	num = 42;
	//int	*ptr = &num;
	int len;
	int	*ptr = NULL;

	printf("Avec printf : \n%p\n", (void *)ptr);

	unsigned long long ptr_value = (unsigned long long)ptr;
	printf("Avec print_ptr : \n");
	len = print_ptr(ptr_value);
	printf("\nlen = %d",len);

	return (0); 
}*/
