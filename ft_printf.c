/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:32:04 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/24 14:35:50 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_parser(const char *str, va_list argument, int i, int j)
{
	int			flag;
	const char	*str1;

	while (*str)
	{
		i = 0;
		str1 = str;
		flag = ft_flags(str);
		while (str[i++] != '%' && str[i - 1])
			j++;
		str = ft_writedoproc(str);
		flag == 1 ? str = ft_whileminus(str) : 0;
		str = ft_skipdotype(str);
		if (*str == 'd' || *str == 'i' || *str == 's' || *str == 'c' ||
		*str == 'p' || *str == 'u' || *str == 'x' || *str == 'X' || *str == '%')
		{
			i = ft_if_type(str1, argument);
			j = j + i;
			str++;
		}
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	argument;
	int		j;

	j = 0;
	i = 0;
	va_start(argument, str);
	i = ft_parser(str, argument, i, j);
	va_end(argument);
	return (i);
}
