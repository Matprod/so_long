/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:43:03 by mvoisin           #+#    #+#             */
/*   Updated: 2023/12/07 17:31:19 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
//# include <stdio.h> // a enleveeeeeeeeeeeeeeeeeeeeeeeeer

void	ft_putchar(char c);

int		print_char(char c);

int		ft_strlen(char *s);

void	ft_putstr(char *s);

int		print_str(char *s);

void	ft_putnbr(int n);

int		print_nbr(int n);

void	putnbr_base(unsigned long n, char *base);

void	put_unsigned_number(unsigned int n);

int		print_unsigned_nbr(unsigned int n);

int		print_percent(void);

int		print_ptr(unsigned long ptr);

int		print_hex(unsigned int num);

int		print_hex_caps(unsigned int num);

int		check_format(va_list args, char c);

int		ft_printf(const char *str, ...);

#endif