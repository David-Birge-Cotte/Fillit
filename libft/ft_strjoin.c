/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:44:53 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/17 12:09:58 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*null_case(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	else
		return (ft_strdup(s1));
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (null_case(s1, s2));
	if ((ret = (char *)malloc(sizeof(char) * (ft_strlen(s1)
	+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	while (*s1)
		ret[i++] = *(s1++);
	while (*s2)
		ret[i++] = *(s2++);
	ret[i] = 0;
	return (ret);
}
