/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:35:04 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:39:03 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
