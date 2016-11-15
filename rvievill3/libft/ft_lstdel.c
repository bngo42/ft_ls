/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:00:29 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/11 15:23:21 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = *alst;
	tmp2 = (*alst)->next;
	while (tmp2 != NULL)
	{
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	del(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
