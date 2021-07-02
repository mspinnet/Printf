/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:23:29 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/24 14:28:54 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr_u(unsigned int n)
{
	unsigned int	i;
	unsigned int	res;
	unsigned int	num;

	i = 1;
	num = n;
	while ((n / 10) > 0)
	{
		n = n / 10;
		i = i * 10;
	}
	while (i > 0)
	{
		res = (num / i) + '0';
		num = num % i;
		write(1, &res, 1);
		i = i / 10;
	}
}

int		ft_lensim_u(unsigned int arg)
{
	int	len;

	len = 0;
	if (arg == 0)
		len = 1;
	while (arg > 0)
	{
		arg = arg / 10;
		len++;
	}
	return (len);
}

void	ft_if_flag0_u(int width, int accur, unsigned int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (width-- > 0)
			write(1, " ", 1);
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
	}
	if (width != 0 && accur == 0)
	{
		while (width-- > 0)
			write(1, " ", 1);
		ft_putnbr_u(arg1);
	}
	if (width == 0 && accur != 0)
	{
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
	}
}

void	ft_if_flag1_u(int width, int accur, unsigned int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (width != 0 && accur == 0)
	{
		ft_putnbr_u(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (width == 0 && accur != 0)
	{
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
	}
}

void	ft_if_flag2_u(int width, int accur, unsigned int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (width-- > 0)
			write(1, " ", 1);
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
	}
	if (width != 0 && accur == 0)
	{
		while (width-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
	}
	if (width == 0 && accur != 0)
	{
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_u(arg1);
	}
}
