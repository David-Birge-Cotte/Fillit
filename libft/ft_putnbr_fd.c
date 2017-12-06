/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:37:21 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 11:37:22 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int i;
	int flag;

	i = 1000000000;
	flag = 0;
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
		ft_putchar_fd('-', fd);
	while (i)
	{
		if (nb / i || flag)
		{
			ft_putchar_fd((nb / i < 0 ? nb / -i : nb / i) + '0', fd);
			flag = 1;
		}
		nb %= i;
		i /= 10;
	}
}
