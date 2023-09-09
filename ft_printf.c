/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:13:49 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/09 16:52:12 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putc(char c, t_memo *memo)
{
    ft_putchar_fd(c, memo->fd);
    memo->nb += 1;
}

char    *ft_fmt(t_memo *memo, const char *s)
{
    s++ ;
    if (*s == '%')
        ft_putc(*s, memo);
    return ((char *) s);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    t_memo  memo;
    
    memo.fd = 1;
    memo.nb = 0;
    va_start (args, s);
    while (*s)
    {
        if(*s != '%')
            ft_putc(*s, &memo);
        else
            s = ft_fmt(&memo, s);
        s++ ;
    }
    va_end(args);
    return (memo.nb);
}
