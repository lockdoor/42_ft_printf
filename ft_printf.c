/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:13:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/14 14:17:01 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
** Error Code;
** 1. ft_pf_fmt
** 2. ft_pf_flags
*/

char	*ft_pf_flags(const char *s, t_memo *memo)
{
	(void) memo;
	while (*s && !ft_strchr(CONVENTION, *s))
	{
		// z_pad
		if (*s >= '0' && *s <='9')
		{
			if (*s == '0')
			{
				memo->z_pad = TRUE;
				s++ ;
			}
			while (*s >= '0' && *s <= '9')
			{
				memo->n_pad = (memo->n_pad) * 10 + (*s - '0');
				s++ ;
			}
		}
		
		// l_just
		else if (*s == '-')
		{
			memo->l_just = TRUE;
			s++ ;
			if(*s == '*')
			{
				memo->n_pad = va_arg(*memo->args, int);
				s++ ;
			}
			while (*s >= '0' && *s <= '9')
			{
				memo->n_pad = (memo->n_pad * 10) + (*s - '0');
				s++ ;
			}
		}

		// pre
		else if (*s == '.')
		{
			memo->pre = TRUE;
			memo->z_pad = FALSE;
			s++ ;
			while (*s >= '0' && *s <= '9')
			{
				memo->n_pre = (memo->n_pre * 10) + (*s - '0');
				s++ ;
			}
		}
		// printf ("memo->n_pad: %d\n", memo->n_pad);
	}
	if (!ft_strchr(CONVENTION, *s))
		exit (-1);
	return ((char *) s);
}


char	*ft_pf_fmt(const char *s, t_memo *memo)
{
	s++ ;
	if (ft_strchr(FLAGS, *s) || (*s >= '0' && *s <= '9'))
		s = ft_pf_flags (s, memo);
	// printf ("s: %c\n", *s);
	if (*s == '%')
		ft_putc (*s, memo);
	else if (*s == 'c')
		ft_conv_c (memo);
	else if (*s == 's')
		ft_conv_s (memo);
	else if (*s == 'p')
		ft_conv_p (*s, memo);
	else if (*s == 'd' || *s == 'i')
		ft_conv_d (memo);
	else if (*s == 'u')
		ft_conv_u (memo);
	else if (*s == 'x' || *s == 'X')
		ft_conv_x (*s, memo);
	else
		memo->nb = -1;
	s++ ;
	return ((char *) s);
}

void	ft_pf_init_memo(va_list *args, t_memo *memo)
{
	memo->fd = 1;
	memo->nb = 0;
	memo->args = args;
	memo->conv = 0;
	memo->l_just = FALSE;
	memo->z_pad = FALSE;
	memo->pre = FALSE;
	memo->n_pad = 0;
	memo->n_pre = 0;
}

void	ft_pf_reset_flags(t_memo *memo)
{
	memo->conv = 0;
	memo->l_just = FALSE;
	memo->z_pad = FALSE;
	memo->pre = FALSE;
	memo->n_pad = 0;
	memo->n_pre = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_memo	memo;

	ft_pf_init_memo (&args, &memo);
	va_start (*memo.args, s);
	while (*s && memo.nb != -1)
	{
		if (*s != '%')
		{
			ft_putc (*s, &memo);
			s++ ;
			continue ;
		}
		s = ft_pf_fmt (s, &memo);
		ft_pf_reset_flags (&memo);
	}
	va_end(*memo.args);
	return (memo.nb);
}
