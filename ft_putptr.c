/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:23:16 by sarif             #+#    #+#             */
/*   Updated: 2023/12/13 16:28:12 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	do_putptr(unsigned long n, char *base, int *counter)
{
	if (n >= 16)
	{
		do_putptr(n / 16, base, counter);
		ft_putchar(base[n % 16], counter);
	}
	else if (n < 16)
		ft_putchar(base[n], counter);
}

void	ft_putptr(unsigned long n, char *base, int *counter)
{
	ft_putstr("0x", counter);
	do_putptr(n, base, counter);
}
