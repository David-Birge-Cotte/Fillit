/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:21:54 by fbertoia          #+#    #+#             */
/*   Updated: 2017/09/15 16:21:56 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}
