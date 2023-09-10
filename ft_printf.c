/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:13:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/10 17:05:10 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// char	*ft_pf_left_pad(const char *s, t_memo *memo)
// {
// 	memo->l_pad = 1;
// 	s++ ;
// 	return ((char *) s);
// }

char	*ft_pf_flags(const char *s, t_memo *memo)
{
	(void) memo;
	while (*s && !ft_strchr(CONVENTION, *s))
	{
		if (*s == '-')
		{
			memo->l_pad = 1;
			s++ ;
			while (*s >= '0' && *s <= '9')
			{
				memo->n_pad = (memo->n_pad * 10) + (*s - '0');
				s++ ;
			}
			printf ("memo->n_pad: %d\n", memo->n_pad);
		}
	}
	if (!ft_strchr(CONVENTION, *s))
		exit (-1);
	// printf ("s: %p, %c\n", s, *s);
	// s++ ;
	return ((char *) s);
}

char	*ft_pf_fmt(const char *s, t_memo *memo)
{
	s++ ;
	if (ft_strchr(FLAGS, *s))
		s = ft_pf_flags (s, memo);
	if (*s == '%')
		ft_putc (*s, memo);
	if (*s == 'c')
		ft_conv_c (memo);
	if (*s == 's')
		ft_conv_s (memo);
	if (*s == 'p')
		ft_conv_p (*s, memo);
	if (*s == 'd' || *s == 'i')
		ft_conv_d (memo);
	if (*s == 'u')
		ft_conv_u (memo);
	if (*s == 'x' || *s == 'X')
		ft_conv_x (*s, memo);
	// else
	// 	exit (-1);
	return ((char *) s);
}

void	ft_pf_init_memo(va_list *args, t_memo *memo)
{
	memo->fd = 1;
	memo->nb = 0;
	memo->args = args;
	memo->conv = 0;
	memo->l_pad = 0;
	memo->n_pad = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_memo	memo;

	ft_pf_init_memo (&args, &memo);
	va_start (*memo.args, s);
	while (*s)
	{
		if (*s != '%')
			ft_putc (*s, &memo);
		else
			s = ft_pf_fmt (s, &memo);
		s++ ;
	}
	va_end(*memo.args);
	return (memo.nb);
}
