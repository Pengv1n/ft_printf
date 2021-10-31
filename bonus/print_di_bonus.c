/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:35:34 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 12:35:39 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_di(va_list argv)
{
	int	size;
	char	*tmp;

	tmp = ft_itoa(va_arg(argv, int));
	ft_putstr_fd(tmp, 1);
	size = ft_strlen(tmp);
	free(tmp);
	return (size);
}
