/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 00:17:43 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/11 00:17:44 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *next;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (new == NULL)
		{
			new = f(lst);
			next = new;
		}
		else
		{
			next->next = f(lst);
			next = next->next;
		}
		lst = lst->next;
	}
	return (new);
}
