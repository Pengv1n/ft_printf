/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:47:50 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:42:17 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_bonus(int f, int t)
{
	if (f == '#')
	{
		if (t == 'x')
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
	return (0);
}

void	check_format(int f, int t, int *size, va_list argv)
{
	va_list	copy;

	va_copy(copy, argv);
	if (f == '#' && ft_strchr("xX", t))
	{
		if (va_arg(copy, int) != 0)
			*size = print_bonus(f, t);
	}
	if ((f == ' ' || f == '+') && ft_strchr("di", t))
	{
		if (va_arg(copy, int) >= 0)
			*size = print_bonus(f, t);
	}
}

int	format_conv_bonus(int f, int t, va_list argv)
{
	int	size;

	size = 0;
	check_format(f, t, &size, argv);
	if (t == 'c' || t == 's')
		return (print_cs(t, argv) + size);
	if (t == 'p')
		return (print_p(argv) + size);
	if (t == 'd' || t == 'i')
		return (print_di(argv) + size);
	if (t == 'u')
		return (print_u(argv) + size);
	if (t == 'x' || t == 'X')
		return (print_x_upx(t, argv) + size);
	if (t == '%')
	{
		ft_putchar_fd('%', 1);
		return (1 + size);
	}
	return (size);
}
