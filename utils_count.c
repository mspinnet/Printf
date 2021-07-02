/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:40:17 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/24 14:34:29 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_count1(int i, int accur, int width)
{
	if (width > i && accur >= i && width >= accur)
		i = (width - accur) + accur;
	else if (width > i && accur >= i && width < accur)
		i = accur;
	else if (width >= i && accur <= i)
		i = i + (width - i);
	else if (width <= i && accur >= i)
		i = i + (accur - i);
	return (i);
}

int	ft_count2(int i, int accur, int width)
{
	if (width > i && accur >= i && width >= accur)
		i = (width - accur) + accur;
	else if (width >= i && accur >= i && width < accur)
		i = accur;
	else if (width > i && accur < i)
		i = i + (width - i);
	else if (width < i && accur > i)
		i = i + (accur - i);
	return (i);
}

int	ft_count3(int i, int accur, int width)
{
	if (width > i && accur > i)
		i = i + (width - i);
	else if (width > i && accur < 0)
		i = i + (width - i);
	else if (width > accur & accur == 0)
		i = width;
	else if (width > accur && accur > 0)
		i = (width - accur) + accur;
	return (i);
}
