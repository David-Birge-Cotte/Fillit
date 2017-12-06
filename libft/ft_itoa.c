/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:44:18 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 10:44:19 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*ret;
	int		flag;
	int		nb;
	int		i;

	if ((ret = (char *)malloc(sizeof(char) * 11)) == NULL)
		return (NULL);
	flag = 0;
	nb = 1000000000;
	if (!(i = 0) && n == 0)
		ret[i++] = '0';
	if (n < 0)
		ret[i++] = '-';
	while (nb)
	{
		if (n / nb || flag)
		{
			ret[i++] = '0' + (n > 0 ? n / nb : n / -nb);
			flag = 1;
		}
		n %= nb;
		nb /= 10;
	}
	ret[i] = 0;
	return (ret);
}
