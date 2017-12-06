/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:08:07 by fbertoia          #+#    #+#             */
/*   Updated: 2017/11/10 22:08:17 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if ((new->content = malloc(sizeof(content) * content_size)) == NULL)
			return (NULL);
		ft_memmove(new->content, content, sizeof(content) * content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
