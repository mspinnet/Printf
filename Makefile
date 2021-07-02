# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 17:02:17 by mspinnet          #+#    #+#              #
#    Updated: 2020/11/23 14:46:58 by mspinnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_type.c ft_type1.c utils_d_i1.c utils_d_i2.c utils_p.c utils_s.c utils_u.c utils_x.c utils_xx.c utils.c utils2.c utils_count.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

GCC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM		= rm -f

ARRC	= ar rc

FT_H	= header.h

all:	${NAME}

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${ARRC} ${NAME} ${OBJS}
		${ARRC} ${NAME} ${FT_H}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
