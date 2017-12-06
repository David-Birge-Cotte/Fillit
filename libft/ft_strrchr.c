/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:10:52 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 19:10:54 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		i;

	i = ft_strlen(s);
	ret = (char *)s;
	if (!c)
		return (ret + i);
	i--;
	while (i > 0 && ret[i] != c)
		i--;
	if (ret[i] == c)
		return (ret + i);
	else
		return (NULL);
}
