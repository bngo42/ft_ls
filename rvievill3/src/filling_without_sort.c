/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_without_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:14:24 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:14:25 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		filling_first(t_lst **start, char *res)
{
	if (res != NULL)
	{
		first_size(*start);
		filling_size(*start);
	}
}

void			create_lst_f(t_lst **start, char *name, char *rep, char *opt)
{
	t_lst		*new;
	t_lst		*tmp;

	tmp = *start;
	if ((*start)->pos == -1)
	{
		filling_struct(*start, name, rep, opt);
		filling_first(start, ft_strchr(opt, 'l'));
	}
	else
	{
		new = (t_lst *)ft_memalloc(sizeof(t_lst));
		if (new == NULL && start == NULL)
			*start = new;
		filling_struct(new, name, rep, opt);
		if (ft_strchr(opt, 'l') != NULL)
			cmp_optl(*start, new, opt);
		if (new != NULL)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}
