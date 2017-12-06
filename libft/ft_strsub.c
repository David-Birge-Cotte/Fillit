/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:28:59 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 13:29:01 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
