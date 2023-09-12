/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:33:59 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/11 17:13:09 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(t_memo *memo)
{
	int	c;

	c = (int) va_arg (*memo->args, int);
	ft_putc(c, memo);
}

void	ft_conv_s(t_memo *memo)
{
	char	*s;

	s = va_arg (*memo->args, char *);
	if (s == NULL)
		s = "(null)";
	if (memo->n_pad)
	{
		if (memo->l_pad)
		{
			while (*s)
			{
				ft_putc(*s, memo);
				s++ ;
				memo->n_pad-- ;
			}
			while (memo->n_pad > 0)
			{
				ft_putc(32, memo);
				memo->n_pad-- ;
			}
		}
		else
		{
			int n_pad = memo->n_pad - ft_strlen (s); 
			while (n_pad > 0)
			{
				ft_putc(32, memo);
				n_pad --;
			}
			while (*s)
				ft_putc(*s++, memo);
		}
		memo->n_pad = 0;
	}
	ft_puts(s, memo);
}

void	ft_conv_p(char conv, t_memo *memo)
{
	unsigned long	addr;
	char			*prefix;

	memo->conv = conv;
	prefix = "0x";
	addr = (unsigned long) va_arg (*memo->args, unsigned long);
	ft_puts (prefix, memo);
	ft_putx (addr, memo);
}

void	ft_conv_d(t_memo *memo)
{
	int	n;
	int i;

	n = (int) va_arg (*memo->args, int);
	if (memo->n_pad)
	{
		i = memo->nb;
		if (memo->l_pad)
		{			
			ft_putn (n, memo);
			i = memo->nb - i;
			while (memo->n_pad - i > 0)
			{
				ft_putc(32, memo);
				memo->n_pad-- ;
			}
		}
		else
		{
			ft_putn (n, memo);
			i = memo->nb - i;
			while (memo->n_pad - i > 0)
			{
				ft_putc(32, memo);
				memo->n_pad --;
			}
		}
		memo->n_pad = 0;
	}
	else
		ft_putn (n, memo);
}

void	ft_conv_u(t_memo *memo)
{
	unsigned int	u;

	u = (unsigned int) va_arg (*memo->args, unsigned int);
	ft_putu(u, memo);
}
