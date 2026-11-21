/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:32:06 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/11/21 10:49:55 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int p, int is_up)
{
	char	*hex;
	char	print[9];
	int		i;

	if (is_up)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 8;
	print[i] = '\0';
	if (p == 0)
		return (write(1, "0", 1));
	while (p > 0)
	{
		print[--i] = hex[p % 16];
		p /= 16;
	}
	return (write(1, print + i, 8 - i));
}
