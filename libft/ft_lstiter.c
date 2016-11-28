/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:58:36 by bngo              #+#    #+#             */
/*   Updated: 2015/12/23 13:06:58 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *ptr1;
	t_list *ptr2;

	if (!lst || !f)
		return ;
	ptr1 = lst;
	ptr2 = lst->next;
	while (ptr2 != NULL)
	{
		f(ptr1);
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	f(ptr1);
}
