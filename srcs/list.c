/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:06:48 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/03 11:07:08 by lvalenti         ###   ########.fr       */
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

// void		add_list(t_rep *begin, t_rep *new)
// {
// 	t_rep *tmp;
//
// 	tmp = begin;
// 	if (!tmp)
// 		tmp = new;
// 	else
// 	{
// 		while (tmp->next && ft_strcmp(tmp->name2, new->name2) < 0)
// 				tmp = tmp->next;
// 		if (ft_strcmp(tmp->name2, new->name2) < 0)
// 		{
// 			if (tmp->next)
// 				tmp->next->prev = new;
// 			new->next = tmp->next;
// 			tmp->next = new;
// 			new->prev = tmp;
// 		}
// 		else
// 		{
// 			if (tmp->prev)
// 				tmp->prev->next = new;
// 			new->next = tmp;
// 			new->prev = tmp->prev;
// 			tmp->prev = new;
// 		}
// 	}
// }

// void		add_list(t_rep **begin, t_rep *new)
// {
// 	t_rep *tmp;
// 	t_rep *tmp2;
//
// 	if (!(*begin))
// 		(*begin) = new;
// 	else if (ft_strcmp((*begin)->name2, new->name2) < 0)
// 	{
// 		tmp = *begin;
// 		while (*begin && ft_strcmp((*begin)->name2, new->name2) < 0)
// 		{
// 			tmp2 = *begin;
// 			*begin = (*begin)->next;
// 		}
// 		if (tmp2->next)
// 			tmp2->next->prev = new;
// 		new->next = tmp2->next;
// 		tmp2->next = new;
// 		new->prev = tmp2;
// 		*begin = tmp;
// 	}
// 	else
// 	{
// 		if ((*begin)->prev)
// 			(*begin)->prev->next = new;
// 		new->next = *begin;
// 		new->prev = (*begin)->prev;
// 		(*begin)->prev = new;
// 		*begin = new;
// 	}
// }

void		add_list(t_rep *begin, char *str)
{
	t_rep *tmp;
	t_rep *new;

	new = NULL;
	if (!(new = (t_rep *)malloc(sizeof(t_rep))))
		return ;
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
		while (tmp && tmp->next != NULL)
		{
			if (tmp->next)
				tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
	}
}
