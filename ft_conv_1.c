/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:33:59 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/14 10:50:48 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(t_memo *memo)
{
	int	c;

	c = (int) va_arg (*memo->args, int);
	ft_putc(c, memo);
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



void	ft_conv_u(t_memo *memo)
{
	unsigned int	u;

	u = (unsigned int) va_arg (*memo->args, unsigned int);
	ft_putu(u, memo);
}
