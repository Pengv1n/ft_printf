/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:55:59 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/25 12:21:32 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     size_uns(unsigned int uns_n)
{
        int     i;

        i = 0;
        if (uns_n == 0)
                i = 1;
        while (uns_n)
        {
                uns_n = uns_n / 10;
                i++;
        }
        return (i);
}

char    *ft_utoa(int n)
{
        int     i;
        unsigned int    uns_n;
        char    *ret;

        uns_n = (unsigned int)n;
        i = size_uns(uns_n);
        ret = (char *)malloc(sizeof(char) * (i + 1));
        if (!ret)
                return (NULL);
        if (uns_n == 0)
		{
	        ret[0] = '0';
        }
		ret[i] = '\0';
        i--;
        while (uns_n)
        {
                ret[i] = uns_n % 10 + '0';
                uns_n = uns_n / 10;
                i--;
        }
        return (ret);
}

int	print_u(va_list argv)
{
	int	size;
	char	*tmp;

	tmp = ft_utoa(va_arg(argv, int));
	ft_putstr_fd(tmp, 1);
	size = ft_strlen(tmp);
	free(tmp);
	return (size);
}