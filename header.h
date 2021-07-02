/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:41:56 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/24 14:36:07 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int			ft_printf(const char *str, ...);
void		ft_putnbr_fd(int n);
void		ft_putnbr_u(unsigned int n);
void		ft_putchar_fd(char c);
int			ft_atoi(const char *str);
int			ft_width(const char *str, va_list argument);
int			ft_lensim(int arg);
int			ft_lensim_u(unsigned int arg);
int			ft_accuracy(const char *str, va_list argument);
int			ft_accminus(int accur, int arg1, int width);
int			ft_if_d_i(va_list argument, int flag, int accur, int width);
const char	*ft_writedoproc(const char *str);
const char	*ft_skipdotype(const char *str);
const char	*ft_whileminus(const char *str);
int			ft_flags(const char *str);
void		ft_putnbr_x(unsigned int n);
int			ft_lensim_x(unsigned int arg);
void		ft_if_flag0_x(int width, int accur, unsigned int arg1);
void		ft_if_flag1_x(int width, int accur, unsigned int arg1);
void		ft_if_flag2_x(int width, int accur, unsigned int arg1);
void		ft_putnbr_p(unsigned long long int n);
int			ft_lensim_p(unsigned long long int arg);
void		ft_if_flag0_p(int width, int accur, unsigned long long int arg1);
void		ft_if_flag1_p(int width, int accur, unsigned long long int arg1);
void		ft_if_flag2_p(int width, int accur, unsigned long long int arg1);
void		ft_putnbr_xx(unsigned int n);
int			ft_lensim_xx(unsigned int arg);
void		ft_if_flag0_xx(int width, int accur, unsigned int arg1);
void		ft_if_flag1_xx(int width, int accur, unsigned int arg1);
void		ft_if_flag2_xx(int width, int accur, unsigned int arg1);
int			ft_parser(const char *str, va_list argument, int i, int j);
void		ft_if_flag0(int width, int accur, int arg1);
void		ft_if_flag1(int width, int accur, int arg1);
void		ft_if_flag2(int width, int accur, int arg1);
void		ft_if_flag0_u(int width, int accur, unsigned int arg1);
void		ft_if_flag1_u(int width, int accur, unsigned int arg1);
void		ft_if_flag2_u(int width, int accur, unsigned int arg1);
int			ft_if_u(va_list argument, int flag, int accur, int width);
void		ft_minint1(int width, int accur, int flag);
void		ft_minint2(int width, int accur, int flag);
void		ft_minint(int width, int accur, int flag);
int			ft_if_type(const char *str, va_list argument);
int			ft_len_s(char *arg1);
int			ft_if_c(va_list argument, int flag, int width);
int			ft_if_s(va_list argument, int flag, int width, int accur);
int			ft_if_x(va_list argument, int flag, int accur, int width);
int			ft_if_xx(va_list argument, int flag, int accur, int width);
int			ft_if_p(va_list argument, int flag, int accur, int width);
int			ft_if_proc(int flag, int width);
int			ft_count(const char *str, int i, int width, int accur);
int			ft_puts(char *s, int accur);
void		ft_accurzero(int width);
void		ft_for_di(int flag, int width, int accur, int arg1);
int			ft_count1(int i, int accur, int width);
int			ft_count2(int i, int accur, int width);
int			ft_count3(int i, int accur, int width);

#endif
