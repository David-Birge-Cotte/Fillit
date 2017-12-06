/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:03:21 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/17 15:03:03 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char *ret;

	ret = (char *)s;
	while (*ret && *ret != c)
		ret++;
	if (*ret == c)
		return (ret);
	else
		return (NULL);
}
