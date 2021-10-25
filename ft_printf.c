/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:20:36 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/25 12:19:16 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argv;
	int	i;
	int	size;

	i = 0;
	size = 0;
	va_start(argv, str);
	if (!str)
		return (-1);
	while (str[size])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			size += format_conv(str[i + 1], argv);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i],1);
			size++;
		}
		i++;
	}
	va_end(argv);
	return (size);
}
