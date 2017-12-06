/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:06:12 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 12:06:13 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if ((ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
