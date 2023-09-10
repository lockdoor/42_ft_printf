/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:33:59 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/10 10:41:27 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(t_memo *memo)
{
	char	c;

	c = (char) va_arg (memo->args, int *);
	ft_putc(c, memo);
}

void	ft_conv_s(t_memo *memo)
{
	char	*s;

	s = va_arg (memo->args, char *);
	if (s == NULL)
		s = "(null)";
	ft_puts(s, memo);
}

void	ft_conv_p(t_memo *memo)
{
	unsigned long	addr;
	char			*prefix;

	prefix = "0x";
	addr = (unsigned long) va_arg (memo->args, unsigned long *);
	ft_puts (prefix, memo);
	ft_putx (addr, memo);
}

void	ft_conv_d(t_memo *memo)
{
	int	n;

	n = (int) va_arg (memo->args, int *);
	ft_putn (n, memo);
}

void	ft_conv_u(t_memo *memo)
{
	unsigned int	u;

	u = (unsigned int) va_arg (memo->args, unsigned int *);
	ft_putu(u, memo);
}
