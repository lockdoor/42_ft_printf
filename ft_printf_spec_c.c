/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 08:38:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/16 09:36:38 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printf_spec_c(const char *s, t_memo *memo)
{
    int c;

    if (*s == '%')
        c = '%';
    else
        c = va_arg (*memo->args, int);
    if (memo->l_just)
        ft_printf_putc(c, memo);
    while (memo->n_pad > 1)
    {
        ft_printf_putc(32, memo);
        memo->n_pad-- ;
    }
    if (!memo->l_just)
        ft_printf_putc(c, memo);
}
