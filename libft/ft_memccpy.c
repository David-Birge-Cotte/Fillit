/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:50:38 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/09 14:50:39 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*ret;

	i = 0;
	tmp = (unsigned char *)src;
	ret = (unsigned char *)dst;
	while (i < n && tmp[i] != (unsigned char)c)
	{
		ret[i] = tmp[i];
		i++;
	}
	if (i < n && tmp[i] == (unsigned char)c)
	{
		ret[i] = tmp[i];
		return (dst + (i + 1));
	}
	else
		return (NULL);
}
