/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:19:48 by sarif             #+#    #+#             */
/*   Updated: 2023/12/15 13:59:50 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fun(char c, va_list args, int *counter)
{
	if (c == 'c')
		ft_putchar (va_arg (args, int), counter);
	else if (c == '%')
		ft_putchar('%', counter);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", counter);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", counter);
	else if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int), counter);
	else if (c == 'p')
		ft_putptr(va_arg(args, unsigned long), "0123456789abcdef", counter);
	else
		ft_putchar(c, counter);
}

int	ft_printf(const char *format, ...)
{
	int			counter;
	int			i;
	va_list		args;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start (args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i])
				fun(format[i], args, &counter);
			else
				break ;
		}
		else
			ft_putchar(format[i], &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
