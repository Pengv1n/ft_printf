/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:10:44 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:19:22 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_cs(int c, va_list argv)
{
	char	*arg;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(argv, int), 1);
		return (1);
	}
	else
	{
		arg = va_arg(argv, char *);
		if (!arg)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		else
		{
			ft_putstr_fd(arg, 1);
			return (ft_strlen(arg));
		}
	}
}
