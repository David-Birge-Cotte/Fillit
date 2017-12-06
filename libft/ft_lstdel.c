/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:53:56 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 23:53:59 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*sec;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		sec = tmp->next;
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = sec;
	}
	(*del)(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
