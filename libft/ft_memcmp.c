/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:52:08 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/09 20:20:06 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	size_t			tmp;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	tmp = 0;
	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	while (*ucs1 == *ucs2 && tmp + 1 < n)
	{
		ucs1++;
		ucs2++;
		tmp++;
	}
	return (*ucs1 - *ucs2);
}
