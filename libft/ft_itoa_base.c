/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:32:29 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/12 21:42:22 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*base_val;
	char	*ret;
	int		i;

	i = 0;
	base_val = "0123456789ABCDEF";
	if ((ret = (char*)malloc(sizeof(char) * 33)) == NULL)
		return (NULL);
	if (base < 2 || base > 16)
		return (NULL);
	if (!value)
		ret[i++] = base_val[0];
	if (value < 0)
		return ("ERROR : NEGATIVE NUMBER");
	while (value > 0)
	{
		ret[i] = base_val[value % base];
		value /= base;
		i++;
	}
	ret[i] = 0;
	return (ft_strrev(ret));
}
