/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:11:40 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/11/21 10:18:04 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		i;
	int		isneg;
	long	n;
	char	arr[12];

	i = 11;
	n = nb;
	isneg = 0;
	arr[i] = '\0';
	if (nb < 0)
	{
		isneg = 1;
		n *= -1;
	}
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		arr[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (isneg)
		arr[--i] = '-';
	return (write(1, arr + i, 11 - i));
}
