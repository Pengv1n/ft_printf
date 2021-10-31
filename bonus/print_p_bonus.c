/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:35:50 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:27:58 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	size_hex(size_t add)
{
	int	size;

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

char	*to_hex(size_t add)
{
	int		i;
	char	*hex_data;
	char	*tmp;
	char	*ret;

	hex_data = "0123456789abcdef";
	i = 0;
	tmp = (char *)ft_calloc((size_hex(add) + 1), sizeof(char));
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
	int		size;
	size_t	temp_i;
	char	*temp;

	temp_i = va_arg(argv, size_t);
	if (temp_i == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	temp = to_hex(temp_i);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(temp, 1);
	size = ft_strlen(temp) + 2;
	free(temp);
	return (size);
}
