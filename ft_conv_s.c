/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:51:01 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/14 15:49:04 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static t_bool ft_putstrl(char *s, size_t len, t_memo *memo)
{
	int	write_return;

	write_return = write (memo->fd, s, len);
	if (write_return == -1)
	{
		memo->nb = -1;
		return (FALSE);
	}
	memo->nb += write_return;
	return (TRUE);
}

void	ft_conv_s(t_memo *memo)
{
	char	*s;
	int		s_len;

	s = va_arg (*memo->args, char *);
	if (s == NULL)
		s = "(null)";
	s_len = ft_strlen (s);
	if (memo->pre)
		s_len = memo->n_pre;
	if(memo->l_just)
	{
		if (!ft_putstrl (s, s_len, memo))
			return ;
	}
	while (memo->n_pad - s_len > 0)
	{
		if(!ft_putc (32, memo))
			return ;
		memo->n_pad --;
	}
	if (!memo->l_just)
		ft_putstrl (s, s_len, memo);
}

/*
void	ft_conv_s(t_memo *memo)
{
	char	*s;

	s = va_arg (*memo->args, char *);
	if (s == NULL)
		s = "(null)";
	if (memo->n_pad)
	{
		if (memo->l_just)
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
	}
	ft_puts(s, memo);
}
*/