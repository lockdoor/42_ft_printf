/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:37:27 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/16 13:10:46 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_str(char *s, t_memo *memo)
{
	char	*p;
	int		n;

	if (memo->n_pad > 0 && !memo->l_just)
	{
		n = 0;
		p = s;
		while (*p++ && n++ < memo->n_pre)
			;
		while (n++ < memo->n_pad)
			ft_printf_putc (32, memo);
	}
	n = 0;
	while (*s)
	{
		if (++n > memo->n_pre && memo->n_pre >= 0)
			break ;
		ft_printf_putc (*s++, memo);
	}
	if (memo->n_pad > 0 && memo->l_just)
		while (n++ < memo->n_pad)
			ft_printf_putc (32, memo);
}

void	ft_printf_spec_s(t_memo *memo)
{
	char	*s;

	s = va_arg (*memo->args, char *);
	if (s == NULL)
		s = "(null)";
	ft_printf_str (s, memo);
}
