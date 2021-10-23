/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:42:47 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/24 02:12:16 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_hexX(unsigned int n)
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

char	*to_hexX(int n)
{
	unsigned int	uns_n;
	int	i;
	char	*tmp;
	char	*hex_data;
	char	*ret;

	hex_data = "0123456789abcdef";
	i = 0;
	uns_n = (unsigned int)n;
	tmp = (char *)malloc(sizeof(char) * (size_hexX(uns_n) + 1));
	if (!tmp)
		return (NULL);
	if (uns_n == 0)
		tmp[0] = '0';
	while (uns_n)
	{
		tmp[i++] = hex_data[uns_n % 16];
		uns_n = uns_n / 16;
	}
	ret = ft_strrev(tmp);
	free(tmp);
	return (ret;
}

int	print_xX(int c, va_list argv)
{
	int	size;
	int	i;
	int	*tmp;

	i = -1;
	tmp = to_hexX(va_arg(argv, int));
	if (c == 'X')
		while (temp[++i])
			tmp[i] = ft_toupper(tmp[i]);
	ft_putstr_fd(tmp, 1);
	size = ft_strlen(tmp);
	free(tmp);
	return (size;
}