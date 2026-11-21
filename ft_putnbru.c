/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:28:56 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/11/21 10:12:19 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int nb)
{
	int		i;
	char	arr[11];

	i = 10;
	arr[i] = '\0';
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		arr[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (write(1, arr + i, 10 - i));
}
