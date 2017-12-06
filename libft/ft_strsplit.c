/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:18:02 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 15:18:04 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		word_count(char const *s, char c)
{
	int flag;
	int ret;

	flag = 1;
	ret = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
			flag = 1;
		}
		if (flag && *s)
			ret++;
		flag = 0;
		if (*s)
			s++;
	}
	return (ret);
}

static void		ft_creator(const char *s, char c, char ***ret, int flag)
{
	unsigned int	i;
	size_t			j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			flag = 1;
		}
		if (flag && s[i])
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			(*ret)[k++] = ft_strsub(s, i, j);
		}
		flag = 0;
		if (s[i])
			i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		a;
	int		i;
	char	**ret;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	a = word_count(s, c);
	if ((ret = (char **)malloc(sizeof(char *) * (a + 1))) == NULL)
		return (NULL);
	ft_creator(s, c, &ret, 1);
	ret[a] = NULL;
	return (ret);
}
