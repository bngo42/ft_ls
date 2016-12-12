/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:06:48 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/12 12:35:36 by bngo             ###   ########.fr       */
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
				if (lst->file->d_name[0] == '.')
					lst = lst->next;
				else
				{
					ft_putendl(lst->file->d_name);
					lst = lst->next;
				}
			}
			else
			{
				ft_putendl(lst->file->d_name);
				lst = lst->next;
			}
		}
	}
}

void		ft_list_end(t_rep **begin, t_rep *new)
{
	t_rep *tmp;

	tmp = *begin;
	if (!tmp)
		tmp = new;
	else
	{
		while (tmp->next && ft_strcmp(tmp->file->d_name, new->file->d_name) < 0)
				tmp = tmp->next;
		if (ft_strcmp(tmp->file->d_name, new->file->d_name) < 0)
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
