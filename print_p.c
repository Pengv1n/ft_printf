/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:24:11 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/25 12:20:56 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     size_hex(size_t add)
{
        int     size;

        size = 0;
        if (add == 0)
                size = 1;
        while (add)
        {
                add = add / 16;
                size++;
        }
        return (size);
}

char    *to_hex(size_t add)
{
        int     i;
        char    *hex_data;
        char    *tmp;
        char    *ret;

        hex_data = "0123456789abcdef";
        i = 0;
        tmp = (char *)malloc(sizeof(char) * (size_hex(add) + 1));
        if (!tmp)
                return (NULL);
        if (add == 0)
                tmp[0] = '0';
        while (add)
        {
                tmp[i] = hex_data[add % 16];
                i++;
                add = add / 16;
        }
        ret = ft_strrev(tmp);
        free(tmp);
        return (ret);
}

int	print_p(va_list argv)
{
	int	size;
	size_t	temp_i;
	char	*temp;

	temp_i = va_arg(argv, size_t);
	temp = to_hex(temp_i);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(temp, 1);
	size = ft_strlen(temp) + 2;
	free(temp);
	return (size);
}
