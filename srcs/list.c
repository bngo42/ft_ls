/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:06:48 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/13 12:22:11 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void		ft_printlst(t_rep *lst, t_opt *opt)
{
	//printf("%d\n", opt->pr);
	// if (opt->pr == 1)
	// {
	// 	while (lst->next)
	// 		lst = lst->next;
	// }
	if (opt->l == 0)
	{
		while (lst)
		{
			if (opt->a == 0)
			{
				if (lst->name[0] != '.')
					ft_putendl(lst->name);
				// lst = (!opt->pr) ? lst->next : lst->prev;
			}
			else
			{
				ft_putendl(lst->name);
				// lst = (!opt->pr) ? lst->next : lst->prev;
			}
			lst = lst->next;
		}
	}
}

void		add_list(t_rep **begin, t_rep *new)
{
	t_rep *tmp;

	// printf("adding %s\n", new->name);
	tmp = *begin;
	if (!tmp)
		tmp = new;
	else
	{
		while (tmp->next && ft_strcmp(tmp->name, new->name) < 0)
				tmp = tmp->next;
		if (ft_strcmp(tmp->name, new->name) < 0)
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
