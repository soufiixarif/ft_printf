/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:20:18 by sarif             #+#    #+#             */
/*   Updated: 2023/12/13 16:28:06 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char *base, int *counter)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, base, counter);
		ft_putchar(base[n % 16], counter);
	}
	else if (n < 16)
		ft_putchar(base[n], counter);
}
