/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:51:16 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/22 21:00:09 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putnbr_xx(unsigned int n)
{
	unsigned int	i;
	unsigned int	res;
	unsigned int	num;

	i = 1;
	num = n;
	while ((n / 16) > 0)
	{
		n = n / 16;
		i = i * 16;
	}
	while (i > 0)
	{
		if (num / i <= 9)
			res = (num / i) + '0';
		if (num / i > 9 && num / i < 16)
			res = (num / i - 10) + 'A';
		num = num % i;
		write(1, &res, 1);
		i = i / 16;
	}
}

int		ft_lensim_xx(unsigned int arg)
{
	int	len;

	len = 0;
	if (arg == 0)
		len = 1;
	while (arg > 0)
	{
		arg = arg / 16;
		len++;
	}
	return (len);
}

void	ft_if_flag0_xx(int width, int accur, unsigned int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (width-- > 0)
			write(1, " ", 1);
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
	}
	if (width != 0 && accur == 0)
	{
		while (width-- > 0)
			write(1, " ", 1);
		ft_putnbr_xx(arg1);
	}
	if (width == 0 && accur != 0)
	{
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
	}
}

void	ft_if_flag1_xx(int width, int accur, unsigned int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (width != 0 && accur == 0)
	{
		ft_putnbr_xx(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (width == 0 && accur != 0)
	{
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
	}
}

void	ft_if_flag2_xx(int width, int accur, unsigned int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (width-- > 0)
			write(1, " ", 1);
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
	}
	if (width != 0 && accur == 0)
	{
		while (width-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
	}
	if (width == 0 && accur != 0)
	{
		while (accur-- > 0)
			write(1, "0", 1);
		ft_putnbr_xx(arg1);
	}
}
