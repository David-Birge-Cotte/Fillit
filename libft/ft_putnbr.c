/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:26:25 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/04 16:26:27 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int i;
	int neg;
	int flag;

	i = 1000000000;
	neg = 0;
	flag = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		neg = 1;
		ft_putchar('-');
	}
	while (i >= 1)
	{
		if (nb / i != 0 || flag)
		{
			ft_putchar('0' + (neg ? -(nb / i) : nb / i));
			flag = 1;
		}
		nb %= i;
		i /= 10;
	}
}
