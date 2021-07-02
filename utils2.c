/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:29:35 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/22 17:49:58 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

const char	*ft_writedoproc(const char *str)
{
	while (*str != '%' && *str)
	{
		ft_putchar_fd(*str);
		str++;
	}
	*str == '%' ? str++ : 0;
	return (str);
}

const char	*ft_skipdotype(const char *str)
{
	while (*str != 'd' && *str != 'i' && *str != 's' && *str != 'c' &&
	*str != 'p' && *str != 'u' && *str != 'x' && *str != 'X' &&
	*str != '%' && *str)
		str++;
	return (str);
}

const char	*ft_whileminus(const char *str)
{
	while (*str == '-' && *str)
		str++;
	return (str);
}

void		ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int			ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	res;
	int						znak;

	i = 0;
	znak = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			znak = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	znak == 1 && res > 9223372036854775807 ? res = -1 : 0;
	znak == -1 && res > 9223372036854775807 ? res = 0 : 0;
	return (res * znak);
}
