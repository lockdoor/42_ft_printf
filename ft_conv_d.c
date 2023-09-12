/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:29:38 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/12 09:21:09 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_d(t_memo *memo)
{
	int		n;
	char	*nb_str;
	int		pad;

	n = (int) va_arg (*memo->args, int);
	nb_str = ft_itoa (n);
	n = ft_strlen (nb_str);
	if (memo->n_pad || memo->n_pre)
	{
		if(memo->z_pad)
			pad = '0';
		else
			pad = 32;
		if (memo->l_just)
		{
			ft_puts(nb_str, memo);
			while (memo->n_pad - n > 0)
			{
				ft_putc(pad, memo);
				memo->n_pad-- ;
			}
		}
		else
		{
			if (memo->pre)
			{
				while (memo->n_pad - memo->n_pre > 0)
				{
					ft_putc(32, memo);
					memo->n_pad --;
				}
				while (memo->n_pre - n > 0)
				{
					ft_putc('0', memo);
					memo->n_pre -- ;
				}
			}
			else {
				while (memo->n_pad - n > 0)
				{
					ft_putc(pad, memo);
					memo->n_pad --;
				}
			}
			ft_puts(nb_str, memo);
		}
	}
	else
		ft_puts(nb_str, memo);
	free (nb_str);
}
