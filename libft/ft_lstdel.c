/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:46:24 by bngo              #+#    #+#             */
/*   Updated: 2015/12/23 13:04:37 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr1;
	t_list *ptr2;

	if (!alst || !del)
		return ;
	ptr1 = *alst;
	ptr2 = (*alst)->next;
	while (ptr2 != NULL)
	{
		del(ptr1->content, ptr1->content_size);
		free(ptr1);
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	del(ptr1->content, ptr1->content_size);
	free(ptr1);
	*alst = NULL;
}
