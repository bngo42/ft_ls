/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:28:55 by bngo              #+#    #+#             */
/*   Updated: 2015/12/23 12:55:49 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*tmptr;

	if ((ptr = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		if ((tmptr = ft_memalloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(tmptr, content, content_size);
		ptr->content = tmptr;
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
