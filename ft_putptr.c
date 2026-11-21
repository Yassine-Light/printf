/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:00:45 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/11/21 10:43:41 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	size_t	ptr;
	char	*hex;
	char	print[19];
	int		i;

	if (!p)
		return (write(1, "(nil)", 5));
	hex = "0123456789abcdef";
	ptr = (size_t)p;
	i = 18;
	print[i] = '\0';
	while (ptr > 0)
	{
		print[--i] = hex[ptr % 16];
		ptr /= 16;
	}
	print[--i] = 'x';
	print[--i] = '0';
	return (write(1, print + i, 18 - i));
}
