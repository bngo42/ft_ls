/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:31:24 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:17:35 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	link = (t_list *)malloc(sizeof(t_list));
	if (link)
	{
		if (content)
		{
			link->content = malloc(content_size);
			ft_memcpy(link->content, content, content_size);
			link->content_size = content_size;
		}
		else
		{
			link->content = NULL;
			link->content_size = 0;
		}
		link->next = NULL;
	}
	return (link);
}
