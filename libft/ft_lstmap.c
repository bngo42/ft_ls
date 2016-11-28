/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:08:14 by bngo              #+#    #+#             */
/*   Updated: 2015/12/23 13:16:26 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new2;
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new = f(tmp);
	tmp = tmp->next;
	if (!(newlst = new))
		return (NULL);
	while (tmp != NULL)
	{
		if ((new2 = (t_list*)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new2 = f(tmp);
		new->next = new2;
		new = new2;
		free(new2);
		tmp = tmp->next;
	}
	return (newlst);
}
