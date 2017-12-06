/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:58:46 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/09 13:58:47 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*ret;

	i = 0;
	tmp = (char *)src;
	ret = (char *)dst;
	while (i < n)
	{
		ret[i] = tmp[i];
		i++;
	}
	return ((void*)dst);
}
