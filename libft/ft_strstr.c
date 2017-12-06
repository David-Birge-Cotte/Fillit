/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 23:08:03 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/04 23:08:26 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!to_find[i])
		return ((char *)str);
	while (*str)
	{
		tmp = (char *)str;
		while (tmp[i] == to_find[i] && tmp[i] && to_find[i])
		{
			i++;
		}
		if (to_find[i] == 0)
			return (tmp);
		i = 0;
		str++;
	}
	return (NULL);
}
