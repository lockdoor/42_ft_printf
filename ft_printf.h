/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:46:17 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/14 14:33:21 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define FLAGS "-0.# +"
# define CONVENTION "cspdiuxX%"
# define TRUE 1
# define FALSE 0

typedef unsigned char t_bool;
typedef struct s_memo
{
	int		nb;
	int		fd;
	char	conv;
	t_bool	l_just;
	t_bool	z_pad;
	t_bool	pre;
	int		n_pad;
	int		n_pre;
	va_list	*args;
}	t_memo;

int		ft_printf(const char *s, ...);

// ft_conv_1.c
void	ft_conv_c(t_memo *memo);
void	ft_conv_s(t_memo *memo);
void	ft_conv_p(char conv, t_memo *memo);
void	ft_conv_d(t_memo *memo);
void	ft_conv_u(t_memo *memo);

// ft_conv_2.c
void	ft_conv_x(char conv, t_memo *memo);

// utils.c
t_bool	ft_putc(char c, t_memo *memo);
t_bool	ft_puts(const char *s, t_memo *memo);
void	ft_putx(unsigned long n, t_memo *memo);
void	ft_putn(int n, t_memo *memo);
void	ft_putu(unsigned int n, t_memo *memo);

#endif