/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:49:02 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/17 20:33:12 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 						BINSEARCH
** Function built in order to find any value within an array of any type.
** Returns the index of the element found. Else, it returns (-1).
*/

#include "libft.h"

static int	compare(const void *arr, const void *value, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (*(char *)arr != *(char *)value)
			return (0);
		i++;
	}
	return (1);
}

int			ft_binsearch(const void *arr, const void *value, size_t size,
			size_t length)
{
	size_t i;

	i = 0;
	if (!arr || !value)
		return (-1);
	while (i < length)
	{
		if (compare(arr, value, size))
			return (i);
		arr += size;
		i++;
	}
	return (-1);
}
