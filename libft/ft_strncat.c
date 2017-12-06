/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:36:16 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/08 11:12:51 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = s1;
	i = 0;
	while (*tmp)
	{
		tmp++;
	}
	while (*s2 && i < n)
	{
		*tmp = *s2;
		tmp++;
		s2++;
		i++;
	}
	*tmp = 0;
	return (s1);
}
