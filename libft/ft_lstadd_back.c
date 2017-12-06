/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:38:37 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/20 14:59:43 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**						FT_LSTADD_BACK
**
** Adds an element to a list and returns the last element of the list.
** If the address of the list is null, returns null. If the list has no
** element, it creates an element an return a pointer on it.
*/

#include "libft.h"

t_list	*ft_lstadd_back(t_list **alst, void const *content, size_t content_size)
{
	t_list *ptr;

	if (!alst)
		return (NULL);
	if (!*alst)
		return (ft_lstnew(content, content_size));
	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ft_lstnew(content, content_size);
	return (ptr->next);
}
