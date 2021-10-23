/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:39:45 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/24 02:36:57 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdlib.h"

int	format_conv(int c, va_list argv);
int	ft_printf(const char *str, ...);

int	print_cs(int c, va_list argv);
int	print_di(va_list argv);
int	print_p(va_list argv);
int	print_u(va_list argv);
int	print_xX(int c, va_list argv);
char	*ft_strrev(char *s);

#endif
