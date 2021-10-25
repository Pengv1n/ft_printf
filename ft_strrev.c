/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 02:33:31 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/24 02:36:19 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *s)
{
	int	i;
	int	len;
	char	*ret;

	i = 0;
	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (len)
		ret[i++] = s[--len];
	ret[i] = '\0';
	return (ret);
}
