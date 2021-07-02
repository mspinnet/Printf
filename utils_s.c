/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:27:38 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/23 11:29:40 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_puts(char *s, int accur)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (accur < 0)
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	else
		while (s[i] && i < accur)
		{
			write(1, &s[i], 1);
			i++;
		}
	return (i);
}

void	ft_if_arg_null(char *arg1)
{
	if (arg1 == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
}

int		ft_len_s(char *arg1)
{
	int	len;

	len = 0;
	if (arg1 == NULL)
		len = 6;
	else
		while (arg1[len])
			len++;
	return (len);
}
