/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:20:25 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/24 14:28:50 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_if_u(va_list argument, int flag, int accur, int width)
{
	unsigned int	arg1;
	int				len;

	arg1 = va_arg(argument, unsigned int);
	len = ft_lensim_u(arg1);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	accur <= len && flag == 2 && accur >= 0 ? flag = 0 : 0;
	if (arg1 == 0 && accur == 0 && width == 0)
		return (0);
	else if (arg1 == 0 && accur == 0 && width != 0)
	{
		ft_accurzero(width);
		return (1);
	}
	width = (width > len) ? width - len : 0;
	accur = (accur > len) ? accur - len : 0;
	width == 0 && accur == 0 ? ft_putnbr_u(arg1) : 0;
	if (flag == 0)
		ft_if_flag0_u(width, accur, arg1);
	else if (flag == 1)
		ft_if_flag1_u(width, accur, arg1);
	else if (flag == 2)
		ft_if_flag2_u(width, accur, arg1);
	return (len);
}

int	ft_if_x(va_list argument, int flag, int accur, int width)
{
	unsigned int	arg1;
	int				len;

	arg1 = va_arg(argument, unsigned int);
	len = ft_lensim_x(arg1);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	accur <= len && flag == 2 && accur >= 0 ? flag = 0 : 0;
	if (arg1 == 0 && accur == 0 && width == 0)
		return (0);
	else if (arg1 == 0 && accur == 0 && width != 0)
	{
		ft_accurzero(width);
		return (1);
	}
	width = (width > len) ? width - len : 0;
	accur = (accur > len) ? accur - len : 0;
	width == 0 && accur == 0 ? ft_putnbr_x(arg1) : 0;
	if (flag == 0)
		ft_if_flag0_x(width, accur, arg1);
	else if (flag == 1)
		ft_if_flag1_x(width, accur, arg1);
	else if (flag == 2)
		ft_if_flag2_x(width, accur, arg1);
	return (len);
}

int	ft_if_p(va_list argument, int flag, int accur, int width)
{
	unsigned long long int	arg1;
	int						len;

	arg1 = va_arg(argument, unsigned long long int);
	len = (arg1 == 0) ? 3 : ft_lensim_p(arg1);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	width = (width > len) ? width - len : 0;
	accur <= len && flag == 2 && accur >= 0 ? flag = 0 : 0;
	if (accur > len)
		accur = accur - len;
	else
		accur = 0;
	width == 0 && accur == 0 && arg1 != 0 ? ft_putnbr_p(arg1) : 0;
	width == 0 && accur == 0 && arg1 == 0 ? write(1, "0x0", 3) : 0;
	if (flag == 0)
		ft_if_flag0_p(width, accur, arg1);
	else if (flag == 1)
		ft_if_flag1_p(width, accur, arg1);
	else if (flag == 2)
		ft_if_flag2_p(width, accur, arg1);
	return (len);
}

int	ft_if_xx(va_list argument, int flag, int accur, int width)
{
	unsigned int	arg1;
	int				len;

	arg1 = va_arg(argument, unsigned int);
	len = ft_lensim_xx(arg1);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	accur <= len && flag == 2 && accur >= 0 ? flag = 0 : 0;
	if (arg1 == 0 && accur == 0 && width == 0)
		return (0);
	else if (arg1 == 0 && accur == 0 && width != 0)
	{
		ft_accurzero(width);
		return (1);
	}
	width = (width > len) ? width - len : 0;
	accur = (accur > len) ? accur - len : 0;
	width == 0 && accur == 0 ? ft_putnbr_xx(arg1) : 0;
	if (flag == 0)
		ft_if_flag0_xx(width, accur, arg1);
	else if (flag == 1)
		ft_if_flag1_xx(width, accur, arg1);
	else if (flag == 2)
		ft_if_flag2_xx(width, accur, arg1);
	return (len);
}

int	ft_if_d_i(va_list argument, int flag, int accur, int width)
{
	int	arg1;
	int	len;

	arg1 = va_arg(argument, int);
	len = ft_lensim(arg1);
	width < 0 ? flag = 1 : 0;
	width < 0 ? width = -width : 0;
	arg1 == -2147483648 && accur >= width ? ft_accminus(accur, arg1, width) : 0;
	arg1 == -2147483648 && width > accur ? ft_minint(width, accur, flag) : 0;
	accur <= len && flag == 2 && accur >= 0 ? flag = 0 : 0;
	if (accur == 0 && arg1 == 0 && width == 0)
		return (0);
	else if (accur == 0 && arg1 == 0 && width != 0)
	{
		ft_accurzero(width);
		return (1);
	}
	width = (width > len) ? width - len : 0;
	if (accur >= len)
		accur = (arg1 >= 0) ? accur - len : accur - len + 1;
	else
		accur = 0;
	ft_for_di(flag, width, accur, arg1);
	arg1 < 0 && accur >= 0 ? len = accur + len : 0;
	return (len);
}
