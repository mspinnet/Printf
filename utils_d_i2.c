/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d_i2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:32:21 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/23 17:15:19 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_accminus(int accur, int arg1, int width)
{
	if (arg1 == -2147483648 && accur <= 0 && width == 0)
		write(1, "-2147483648", 11);
	if (arg1 == -2147483648 && accur <= 10 && accur > 0)
		write(1, "-2147483648", 11);
	if (arg1 == -2147483648 && accur > 10)
	{
		accur = accur - 10;
		write(1, "-", 1);
		while (accur-- > 0)
			write(1, "0", 1);
		write(1, "2147483648", 10);
	}
	while (accur-- > 0 && arg1 != -2147483648)
	{
		if (arg1 < 0)
		{
			write(1, "-", 1);
			arg1 = -arg1;
		}
		write(1, "0", 1);
	}
	return (arg1);
}

void	ft_if_flag0(int width, int accur, int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (width-- > 0)
			write(1, " ", 1);
		arg1 = ft_accminus(accur, arg1, width);
		ft_putnbr_fd(arg1);
	}
	if (width != 0 && accur == 0)
	{
		while (width-- > 0)
			write(1, " ", 1);
		ft_putnbr_fd(arg1);
	}
	if (width == 0 && accur != 0)
	{
		arg1 = ft_accminus(accur, arg1, width);
		ft_putnbr_fd(arg1);
	}
	width == 0 && accur == 0 ? ft_putnbr_fd(arg1) : 0;
}

void	ft_if_flag1(int width, int accur, int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		arg1 = ft_accminus(accur, arg1, width);
		ft_putnbr_fd(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (width != 0 && accur == 0)
	{
		ft_putnbr_fd(arg1);
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (width == 0 && accur != 0)
	{
		arg1 = ft_accminus(accur, arg1, width);
		ft_putnbr_fd(arg1);
	}
	width == 0 && accur == 0 ? ft_putnbr_fd(arg1) : 0;
}

void	ft_if_flag2(int width, int accur, int arg1)
{
	if (width != 0 && accur != 0)
	{
		width = (width > accur) ? width - accur : 0;
		while (width-- > 0)
			write(1, " ", 1);
		arg1 = ft_accminus(accur, arg1, width);
		ft_putnbr_fd(arg1);
	}
	if (width != 0 && accur == 0)
	{
		if (arg1 < 0)
		{
			write(1, "-", 1);
			arg1 = -arg1;
		}
		while (width-- > 0)
			write(1, "0", 1);
		ft_putnbr_fd(arg1);
	}
	if (width == 0 && accur != 0)
	{
		arg1 = ft_accminus(accur, arg1, width);
		ft_putnbr_fd(arg1);
	}
	width == 0 && accur == 0 ? ft_putnbr_fd(arg1) : 0;
}

void	ft_for_di(int flag, int width, int accur, int arg1)
{
	if (flag == 0 && arg1 != -2147483648)
		ft_if_flag0(width, accur, arg1);
	else if (flag == 1 && arg1 != -2147483648)
		ft_if_flag1(width, accur, arg1);
	else if (flag == 2 && arg1 != -2147483648)
		ft_if_flag2(width, accur, arg1);
}
