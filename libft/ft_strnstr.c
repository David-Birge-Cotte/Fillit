/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:12:55 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/09 09:12:57 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		tmp = (char *)(haystack + j);
		while (*tmp == needle[i] && (i + j) < (len - 1)
		&& *tmp && needle[i + 1])
		{
			tmp++;
			i++;
		}
		if (*tmp == needle[i] && (!needle[i] || !needle[i + 1]))
			return ((char *)(haystack + j));
		i = 0;
		j++;
	}
	return (NULL);
}
