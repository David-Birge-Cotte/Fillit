/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:52:50 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/05 23:44:35 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int test_val;

	test_val = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (test_val <= nb / 2)
	{
		if (test_val * test_val == nb)
			return (test_val);
		test_val++;
	}
	return (0);
}
