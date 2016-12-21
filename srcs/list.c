/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:06:48 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/21 11:15:55 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_printlst(t_rep *lst, t_opt *opt)
{
	if (opt->l == 0)
	{
		while (lst)
		{
			if (opt->a == 0)
			{
				if (lst->name[0] != '.')
					ft_putendl(lst->name);
			}
			else
				ft_putendl(lst->name);
			lst = lst->next;
		}
	}
}

void		add_list(t_rep **begin, t_rep *new)
{
	t_rep *tmp;

	tmp = *begin;
	if (!tmp)
		tmp = new;
	else
	{
		while (tmp->next && ft_strcmp(tmp->name2, new->name2) < 0)
				tmp = tmp->next;
		if (ft_strcmp(tmp->name2, new->name2) < 0)
		{
			if (tmp->next)
				tmp->next->prev = new;
			new->next = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
		else
		{
			if (tmp->prev)
				tmp->prev->next = new;
			new->next = tmp;
			new->prev = tmp->prev;
			tmp->prev = new;
		}
	}
}
