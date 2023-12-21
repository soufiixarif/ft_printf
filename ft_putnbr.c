/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:20:13 by sarif             #+#    #+#             */
/*   Updated: 2023/12/13 16:28:09 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long n, int *counter)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (n < 0)
	{
		ft_putchar('-', counter);
		n = n * -1;
		ft_putnbr(n, counter);
	}
	else if (n >= 10)
	{
		ft_putnbr (n / 10, counter);
		ft_putnbr (n % 10, counter);
	}
	else
		ft_putchar (n + '0', counter);
}
