/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:36:18 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/11/21 15:46:01 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_unkown(char c)
{
	if (ft_putchar('%') == -1)
		return (-1);
	if (ft_putchar(c) == -1)
		return (-1);
	return (2);
}

static int	format(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_putnbru(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (format == '%')
		return (ft_putchar('%'));
	return (put_unkown(format));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		val;
	int		total;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	total = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == '\0')
				return (va_end(args), -1);
			val = format(*(++fmt), &args);
		}
		else
			val = ft_putchar(*fmt);
		if (val == -1)
			return (va_end(args), -1);
		total += val;
		fmt++;
	}
	va_end(args);
	return (total);
}
