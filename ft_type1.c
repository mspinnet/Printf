/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:23:50 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/23 14:36:12 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_if_c(va_list argument, int flag, int width)
{
	int	arg1;

	arg1 = va_arg(argument, int);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	if (width > 1 && flag == 0)
	{
		width = width - 1;
		while (width-- > 0)
			write(1, " ", 1);
		ft_putchar_fd(arg1);
	}
	else if (width > 1 && flag == 1)
	{
		width = width - 1;
		ft_putchar_fd(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	else if (width <= 1)
		ft_putchar_fd(arg1);
	return (1);
}

int	ft_if_proc(int flag, int width)
{
	int	arg1;

	arg1 = '%';
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	width = (width > 1) ? width - 1 : 0;
	width == 0 ? ft_putchar_fd(arg1) : 0;
	if (width != 0 && (flag == 0 || flag == 2))
	{
		while (width-- > 0)
			if (flag == 0)
				write(1, " ", 1);
			else if (flag == 2)
				write(1, "0", 1);
		ft_putchar_fd(arg1);
	}
	else if (width != 0 && flag == 1)
	{
		ft_putchar_fd(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	return (1);
}

int	ft_if_s(va_list argument, int flag, int width, int accur)
{
	char	*arg1;
	int		len;

	arg1 = va_arg(argument, char *);
	len = ft_len_s(arg1);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	accur < len && accur >= 0 ? len = accur : 0;
	width = (width > len) ? width - len : 0;
	if (width != 0 && flag == 0)
	{
		while (width-- > 0)
			write(1, " ", 1);
		len = (arg1 == NULL) ? ft_puts("(null)", accur) : ft_puts(arg1, accur);
	}
	else if (width != 0 && flag == 1)
	{
		len = (arg1 == NULL) ? ft_puts("(null)", accur) : ft_puts(arg1, accur);
		while (width-- > 0)
			write(1, " ", 1);
	}
	else if (width == 0)
		len = (arg1 == NULL) ? ft_puts("(null)", accur) : ft_puts(arg1, accur);
	return (len);
}

int	ft_if_type(const char *str, va_list argument)
{
	int	i;
	int	f;
	int	width;
	int	accur;

	i = 0;
	f = ft_flags(str);
	width = ft_width(str, argument);
	accur = ft_accuracy(str, argument);
	while (*str != '%')
		str++;
	*str == '%' ? str++ : 0;
	str = ft_skipdotype(str);
	*str == 'd' || *str == 'i' ? i = ft_if_d_i(argument, f, accur, width) : 0;
	*str == 'c' ? i = ft_if_c(argument, f, width) : 0;
	*str == 's' ? i = ft_if_s(argument, f, width, accur) : 0;
	*str == 'u' ? i = ft_if_u(argument, f, accur, width) : 0;
	*str == 'x' ? i = ft_if_x(argument, f, accur, width) : 0;
	*str == 'X' ? i = ft_if_xx(argument, f, accur, width) : 0;
	*str == 'p' ? i = ft_if_p(argument, f, accur, width) : 0;
	*str == '%' ? i = ft_if_proc(f, width) : 0;
	i = ft_count(str, i, width, accur);
	return (i);
}
