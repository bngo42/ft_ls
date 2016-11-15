/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:34:01 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/13 12:02:32 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*new2;
	t_list		*newlst;
	t_list		*tmp;

	tmp = lst;
	if (f == NULL || lst == NULL)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	tmp = tmp->next;
	newlst = new;
	while (tmp)
	{
		if (!(new2 = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		new2 = f(tmp);
		new->next = new2;
		new = new2;
		tmp = tmp->next;
	}
	return (newlst);
}
