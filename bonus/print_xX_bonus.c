/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:36:14 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:32:10 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	size_hex_upx(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*to_hex_upx(int n)
{
	unsigned int	uns_n;
	int				i;
	char			*tmp;
	char			*hex_data;
	char			*ret;

	hex_data = "0123456789abcdef";
	i = 0;
	uns_n = (unsigned int)n;
	tmp = (char *)malloc(sizeof(char) * (size_hex_upx(uns_n) + 1));
	if (!tmp)
		return (NULL);
	if (uns_n == 0)
		tmp[0] = '0';
	while (uns_n)
	{
		tmp[i++] = hex_data[uns_n % 16];
		uns_n = uns_n / 16;
	}
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	free(tmp);
	return (ret);
}

int	print_x_upx(int c, va_list argv)
{
	int		size;
	int		i;
	int		arg;
	char	*tmp;

	i = -1;
	arg = va_arg(argv, int);
	if (!arg)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	tmp = to_hex_upx(arg);
	if (c == 'X')
		while (tmp[++i])
			tmp[i] = ft_toupper(tmp[i]);
	ft_putstr_fd(tmp, 1);
	size = ft_strlen(tmp);
	free(tmp);
	return (size);
}
