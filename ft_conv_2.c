/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:35:07 by pnamnil           #+#    #+#             */
/*   Updated: 2023/09/10 10:35:31 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_x(char conv, t_memo *memo)
{
	unsigned int	x;

	memo->conv = conv;
	x = (unsigned int) va_arg (memo->args, unsigned int *);
	ft_putx(x, memo);
}
