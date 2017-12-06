/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:05:07 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/05 16:05:10 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_sub_strcapitalize(char *tmp, int flag)
{
	while (*tmp)
	{
		while ((*tmp >= 'A' && *tmp <= 'Z') || (*tmp >= 'a' && *tmp <= 'z') ||
		(*tmp >= '0' && *tmp <= '9'))
		{
			if (((*tmp >= 'a' && *tmp <= 'z') || (*tmp >= 'A' && *tmp <= 'Z')
			|| (*tmp >= '0' && *tmp <= '9')) && flag == 1)
			{
				if ((*tmp >= 'a' && *tmp <= 'z'))
					*tmp -= 32;
				flag = 0;
			}
			else
			{
				if (*tmp >= 'A' && *tmp <= 'Z' && flag == 0)
					*tmp += 32;
			}
			tmp++;
		}
		flag = 1;
		if (*tmp)
			tmp++;
	}
	return (tmp);
}

char		*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	ft_sub_strcapitalize(tmp, 1);
	return (tmp);
}
