/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:06:48 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/05 11:01:58 by lvalenti         ###   ########.fr       */
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
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
