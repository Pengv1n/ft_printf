/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:47:50 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/30 18:14:01 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_bonus(int f, int t)
{
	if (f == '#')
	{
		if (f == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		return (2);
	}
	if (f == ' ')
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	if (f == '+')
	{
		ft_putchar_fd('+', 1);
		return (1);
	}
}

void	check_format(int f, int t, int *size, va_list argv)
{
	va_list	copy;

	va_copy(copy, argv);
	if (f == '#' && ft_strchr("xX", c))
	{
		if (va_arg(copy, int) != 0)
			print_bonus(size, f, t);
	}
	if ((f == ' ' || f == '+') && ft_strchr("di", t))
	{
		if (va_arg(copy, int) >= 0)
			*size = print_bonus(size, f, t);
	}
}

int	format_conv_bonus(int f, int t, va_list argv)
{
	int size;

	size = 0;
	check_format(f, t, &size, va_list argv);
	if (c == 'c' || c == 's')
		return (print_cs(c, argv) + size);
	if (c == 'p')
		return (print_p(argv) + size);
	if (c == 'd' || c == 'i')
		return (print_di(argv) + size);
	if (c == 'u')
		return (print_u(argv) + size);
	if (c == 'x' || c == 'X')
		return (print_xX(c, argv) + size);
	if (c == '%')
	{
		ft_putchar_fd('%',1);
		return (1 + size);
	}
	return (size);
}