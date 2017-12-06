/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:21:19 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/16 10:21:34 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;

	i = 0;
	size_dst = ft_strlen(dst);
	if (size <= size_dst || size == 0)
		return (ft_strlen(src) + size);
	while (size_dst + i < size - 1)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + ft_strlen(src));
}
