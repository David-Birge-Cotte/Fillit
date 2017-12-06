/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:18:59 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 12:19:00 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;

	i = 0;
	if (!s)
		return (0);
	if ((ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
