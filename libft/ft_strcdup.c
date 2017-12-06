/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:27:12 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/17 14:13:26 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 							FT_STRCDUP
**
** Copies the string entered up to the first occurence of the  character 'c'.
** In case no character were to be found, it copies the full string into a
** fresh new area.
*/

char	*ft_strcdup(const char *s1, int c)
{
	char	*dest;
	int		a;
	int		b;

	a = 0;
	b = ft_strindex(s1, c);
	if (!s1)
		return (NULL);
	if ((dest = (char *)malloc(sizeof(char) * (b != -1 ? b + 2 : 0))))
	{
		while (s1[a] && s1[a] != c)
		{
			dest[a] = s1[a];
			a++;
		}
		dest[a] = s1[a];
		a++;
		dest[a] = 0;
		return (dest);
	}
	return (NULL);
}
