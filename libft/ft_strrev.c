/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 23:30:25 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/02 12:36:23 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrev(char *str)
{
	char	stock_val;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		stock_val = str[i];
		str[i] = str[j];
		str[j] = stock_val;
		i++;
		j--;
	}
	return (str);
}
