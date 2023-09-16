/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 08:26:03 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/16 13:57:55 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_getsign(const char *s, t_memo *memo)
{
	while (TRUE)
	{
		if (*s == '#')
			memo->prefix_o_x = TRUE;
		else if (*s == '-')
			memo->l_just = TRUE;
		else if (*s == '+')
			memo->plus_sign = '+';
		else if (*s == ' ')
		{
			if (memo->plus_sign == 0)
				memo->plus_sign = ' ';
		}
		else
			break ;
		s++ ;
	}
	return ((char *) s);
}

static char	*ft_printf_getlen(const char *s, int *val, int type, t_memo *memo)
{
	if (ft_isdigit(*s))
	{
		while (ft_isdigit(*s))
		{
			*val = (*val * 10) + (*s - '0');
			s++ ;
		}
	}
	else if (*s == '*')
	{
		*val = va_arg (*memo->args, int);
		if (*val < 0 && type == 0)
		{
			*val = -*val;
			memo->l_just = !memo->l_just;
		}
		s++ ;
	}
	return ((char *) s);
}

char	*ft_printf_getflags(const char *s, t_memo *memo)
{
	if (*s == '0')
	{
		memo->padc = '0';
		s++ ;
	}
	if (ft_isdigit (*s) || *s == '*')
		s = ft_printf_getlen (s, &memo->n_pad, 0, memo);
	if (*s == '.')
	{
		s++ ;
		memo->n_pre = 0;
		memo->padc = 32;
		s = ft_printf_getlen (s, &memo->n_pre, 1, memo);
	}
	return ((char *) s);
}

void	ft_printf_init_memo(va_list *args, t_memo *memo)
{
	memo->cnt = 0;
	memo->fd = 1;
	memo->args = args;
	memo->plus_sign = 0;
	memo->padc = 32;
	memo->n_pad = 0;
	memo->n_pre = -1;
	memo->l_just = FALSE;
	memo->prefix_o_x = FALSE;
	memo->prefix = NULL;
}

void	ft_printf_reset_memo(t_memo *memo)
{
	memo->plus_sign = 0;
	memo->padc = 32;
	memo->n_pad = 0;
	memo->n_pre = -1;
	memo->l_just = FALSE;
	memo->prefix_o_x = FALSE;
	memo->prefix = NULL;
}
