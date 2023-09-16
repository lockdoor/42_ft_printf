/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:10:05 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/16 14:58:08 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** protect if write false, it set memo->nb = -1
*/ 
t_bool	ft_printf_putc(char c, t_memo *memo)
{
	int	write_result;

	write_result = write(memo->fd, &c, 1);
	if (write_result == -1)
	{
		memo->cnt = -1;
		return (FALSE);
	}
	memo->cnt += write_result;
	return (TRUE);
}

static void ft_print_number_h1 (char *n, char *p, int len, t_memo *memo)
{
	int	i;

	if (memo->plus_sign)
	{
		*--p = memo->plus_sign;
		len++ ;
	}
	if (memo->prefix)
	{
		i = 0;
		while (memo->prefix[i])
		{
			*--p = memo->prefix[i];
			len++ ;
		}
	}
	while (len < memo->n_pad && !memo->l_just)
	{
		if (memo->padc == '0' && memo->plus_sign != 0)
		{
			ft_printf_putc(*p++, memo);
			memo->plus_sign = 0;
			// len++ ;
		}
		ft_printf_putc (memo->padc, memo);
		len++ ;
	}
	// while (p < &n[MAX_BUF])
	while (p < n)
	{
		ft_printf_putc (*p++, memo);
	}
	while (len < memo->n_pad && memo->l_just)
	{
		ft_printf_putc (memo->padc, memo);
		len++ ;
	}
}

void	ft_printf_number(long u, t_memo *memo)
{
	char	n[MAX_BUF + 1];
	char	*p;
	int		len;
	// int		i;

	n[MAX_BUF] = 0;
	p = &n[MAX_BUF - 1];
	while (u / memo->base)
	{
		*p-- = memo->base_c[u % memo->base];
		u /= memo->base;
	}
	*p = memo->base_c[u % memo->base];
	len = &n[MAX_BUF] - p;
	while (len < memo->n_pre)
	{
		len++ ;
		*--p = '0';
	}
	ft_print_number_h1 (&n[MAX_BUF], p, len, memo);
	/* this work before seperate function to ft_print_number_h1 */
	// if (memo->plus_sign)
	// {
	// 	*--p = memo->plus_sign;
	// 	len++ ;
	// }
	// if (memo->prefix)
	// {
	// 	i = 0;
	// 	while (memo->prefix[i])
	// 	{
	// 		*--p = memo->prefix[i];
	// 		len++ ;
	// 	}
	// }
	// while (len < memo->n_pad && !memo->l_just)
	// {
	// 	if (memo->padc == '0' && memo->plus_sign != 0)
	// 	{
	// 		ft_printf_putc(*p++, memo);
	// 		memo->plus_sign = 0;
	// 		// len++ ;
	// 	}
	// 	ft_printf_putc (memo->padc, memo);
	// 	len++ ;
	// }
	// while (p < &n[MAX_BUF])
	// {
	// 	ft_printf_putc (*p++, memo);
	// }
	// while (len < memo->n_pad && memo->l_just)
	// {
	// 	ft_printf_putc (memo->padc, memo);
	// 	len++ ;
	// }
}


