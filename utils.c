/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:10:05 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/10 12:08:41 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putc(char c, t_memo *memo)
{
	ft_putchar_fd (c, memo->fd);
	memo->nb += 1;
}

void	ft_puts(const char *s, t_memo *memo)
{
	while (*s)
		ft_putc (*s++, memo);
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
