/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:06:48 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/03 14:33:35 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_printlst(t_rep *lst, t_opt *opt)
{
	t_rep *tmp;

	tmp = lst;
	if (opt->l == 0)
	{
		while (tmp)
		{
			if (opt->a == 0)
			{
				if (tmp->name[0] != '.')
					ft_putendl(tmp->name);
			}
			else
				ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			if (opt->a == 0)
			{
				if (tmp->name[0] != '.')
					aff_stat(tmp, opt->len);
			}
			else if (opt->a == 1)
				aff_stat(tmp, opt->len);
			tmp = tmp->next;
		}
	}
}

void		add_list(t_rep *begin, char *str)
{
	t_rep *tmp;
	t_rep *new;

	new = NULL;
	if (!(new = (t_rep *)malloc(sizeof(t_rep))))
		return ;
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	new->name2 = ft_strjoin(begin->argv, "/");
	new->name = ft_strdup(str);
	new->name2 = ft_strjoin(new->name2, new->name);
	tmp = begin;
	if (begin == NULL)
		begin = new;
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
