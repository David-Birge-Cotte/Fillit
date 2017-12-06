/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:06:00 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/15 09:44:52 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int value;
	int neg;

	value = 0;
	i = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	if (neg)
		return (value * (-1));
	return (value);
}
