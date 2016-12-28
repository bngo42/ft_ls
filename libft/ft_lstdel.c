/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:33:36 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:18:02 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current_elem;
	t_list *next_elem;

	current_elem = *alst;
	while (current_elem)
	{
		next_elem = current_elem->next;
		del(current_elem->content, current_elem->content_size);
		free(current_elem);
		current_elem = next_elem;
	}
	*alst = NULL;
}
