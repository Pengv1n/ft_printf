/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:04:52 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:42:57 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	format_conv(int c, va_list argv)
{
	if (c == 'c' || c == 's')
		return (print_cs(c, argv));
	if (c == 'p')
		return (print_p(argv));
	if (c == 'd' || c == 'i')
		return (print_di(argv));
	if (c == 'u')
		return (print_u(argv));
	if (c == 'x' || c == 'X')
		return (print_x_upx(c, argv));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	format_choice(const char **str, int *size, va_list argv, int i)
{
	int	k;

	k = i;
	if (ft_strchr("# +", (*str)[i + 1]))
	{
		while (!ft_strchr("cspdiuxX", (*str)[++k]))
			;
		*size += format_conv_bonus((*str)[i + 1], (*str)[k], argv);
		i = (k - 1);
	}
	else
		*size += format_conv((*str)[i + 1], argv);
	i++;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	argv;
	int		i;
	int		size;

	if (!str)
		return (-1);
	i = 0;
	size = 0;
	va_start(argv, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("# +cspdiuxX%", str[i + 1]))
			i = format_choice(&str, &size, argv, i);
		else
		{
			ft_putchar_fd(str[i], 1);
			size++;
		}
		i++;
	}
	va_end(argv);
	return (size);
}
