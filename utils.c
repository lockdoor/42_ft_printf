/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:10:05 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/14 14:34:10 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** protect if write false, it set memo->nb = -1
*/ 
t_bool	ft_putc(char c, t_memo *memo)
{
	int	write_result;

	write_result = write(memo->fd, &c, 1);
	if (write_result == -1)
	{
		memo->nb = -1;
		return (FALSE);
	}
	memo->nb += write_result;
	return (TRUE);
}

t_bool	ft_puts(const char *s, t_memo *memo)
{
	while (*s)
	{
		if (!ft_putc (*s++, memo))
			return (FALSE);
	}
	return (TRUE);
}

void	ft_putx(unsigned long n, t_memo *memo)
{
	char	*base;

	if (memo->conv == 'X')
		base = HEX_UPPER;
	else
		base = HEX_LOWER;
	if (n > 15)
		ft_putx (n / 16, memo);
	ft_putc (base[n % 16], memo);
}

void	ft_putu(unsigned int n, t_memo *memo)
{
	if (n > 9)
		ft_putu (n / 10, memo);
	ft_putc (n % 10 + '0', memo);
}

void	ft_putn(int n, t_memo *memo)
{
	long	nb;

	nb = (long) n;
	if (n < 0)
	{
		nb *= -1;
		ft_putc('-', memo);
	}
	if (nb > 9)
		ft_putn (nb / 10, memo);
	ft_putc (nb % 10 + '0', memo);
}
