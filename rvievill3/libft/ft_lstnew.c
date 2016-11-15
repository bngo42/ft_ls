/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:04:41 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/12 17:01:21 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*content2;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(content2 = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(content2, content, content_size);
		list->content = content2;
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
