/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:52:08 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/24 14:34:32 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_width(const char *str, va_list argument)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i] == '%')
		i++;
	if (str[i] == '-' || str[i] == '0')
		while (str[i] == '-' || str[i] == '0')
			i++;
	if (str[i] == '*')
		width = va_arg(argument, int);
	else if (str[i] != '-' && str[i] != '.' && str[i] != 'd' && str[i] != 'i' &&
	str[i] != '*')
		width = ft_atoi(&str[i]);
	return (width);
}

int		ft_accuracy(const char *str, va_list argument)
{
	int	acc;
	int	i;

	acc = -1;
	i = 0;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i] == '%')
		i++;
	while (str[i] != '.' && str[i] != 'd' && str[i] != 'i' && str[i] != 'p' &&
	str[i] != 'c' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' &&
	str[i] != 's' && str[i] != '%' && str[i])
		i++;
	if (str[i] == '.')
		i++;
	else
		return (acc);
	if (str[i] != '*')
		acc = ft_atoi(&str[i]);
	else
		acc = va_arg(argument, int);
	return (acc);
}

int		ft_flags(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != '%' && str[i])
		i++;
	if (str[i] == '%')
		i++;
	if (str[i] == '-')
		flag = 1;
	if (str[i] == '0' && str[i + 1] == '-')
		flag = 1;
	else if (str[i] == '0' && str[i + 1] != '-')
		flag = 2;
	return (flag);
}

int		ft_count(const char *str, int i, int width, int accur)
{
	width < 0 ? width = -width : 0;
	if (*str == 'x' || *str == 'X' || *str == 'u' || *str == 'p')
		i = ft_count1(i, accur, width);
	if (*str == 'd' || *str == 'i')
		i = ft_count2(i, accur, width);
	if (*str == 'c' || *str == '%')
		width > i ? i = i + (width - i) : 0;
	if (*str == 's')
		i = ft_count3(i, accur, width);
	return (i);
}

void	ft_accurzero(int width)
{
	while (width-- > 0)
		write(1, " ", 1);
}
