/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 23:28:40 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/03 14:08:56 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Enables to swap any type of value. a and b are the values to swap. size
** represents the size of the value put within the function (int, char, long)
** and NOT the size of an array!
*/

void	ft_swap(void *a, void *b, size_t size)
{
	char	tmp;
	size_t	i;

	i = 0;
	if (!a || !b)
		return ;
	while (i < size)
	{
		if (a != (b))
		{
			*(char*)a ^= *(char*)b;
			*(char*)b ^= *(char*)a;
			*(char*)a ^= *(char*)b;
		}
		else
		{
			tmp = *(char*)a;
			*(char*)a = *(char*)b;
			*(char*)b = tmp;
		}
		i++;
		a++;
		b++;
	}
}
