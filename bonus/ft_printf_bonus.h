/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.21-school.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:41:30 by aregenia          #+#    #+#             */
/*   Updated: 2021/10/31 23:37:50 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "stdarg.h"
# include "stdlib.h"
# include "../libft/libft.h"

int		format_conv(int c, va_list argv);
int		ft_printf(const char *str, ...);
int		format_conv_bonus(int f, int t, va_list argv);
int		print_cs(int c, va_list argv);
int		print_di(va_list argv);
int		print_p(va_list argv);
int		print_u(va_list argv);
int		print_x_upx(int c, va_list argv);
char	*ft_strrev(char *s);

#endif
