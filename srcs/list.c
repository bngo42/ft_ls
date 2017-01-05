/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:43:09 by bngo              #+#    #+#             */
/*   Updated: 2017/01/05 11:43:41 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		swap_link(t_rep *lst)
{
	t_rep	*tmp;

	if (!lst->prev)
	{
		tmp = lst;
		lst = lst->next;
		tmp->next = lst->next;
		lst->prev = NULL;
		lst->next = tmp;
		tmp->prev = lst;
		if (tmp->next)
			tmp->next->prev = tmp;
	}
	else
	{
		tmp = lst;
		lst->prev->next = lst->next;
		lst = lst->next;
		lst->prev->next = lst->next;
		lst->prev = lst->prev->prev;
		lst->next = tmp;
		tmp->prev = lst;
		if (tmp->next)
			tmp->next->prev = tmp;
	}
}

void		free_lst(t_rep *lst)
{
	while (lst)
	{
		if (lst->prev)
		{
			free(lst->prev->name);
			free(lst->prev->name2);
			free(lst->prev);
		}
		if (lst->next == NULL)
		{
			free(lst->name);
			free(lst->name2);
			free(lst);
			return ;
		}
		lst = lst->next;
	}
}

void		ft_printlst(t_rep *lst, t_opt *opt)
{
	t_rep *tmp;

	tmp = lst;
	while (tmp)
	{
		if (opt->l == 0)
		{
			if (opt->a == 0 && tmp->name[0] != '.')
				ft_putendl(tmp->name);
			else if (opt->a == 1)
				ft_putendl(tmp->name);
		}
		else
		{
			if (opt->a == 0 && tmp->name[0] != '.')
				aff_stat(tmp, opt->len);
			else if (opt->a == 1)
				aff_stat(tmp, opt->len);
		}
		tmp = tmp->next;
	}
}

void		sort_ascii(t_rep *tmp, t_rep *new)
{
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

void		add_list(t_rep *begin, char *str)
{
	t_rep	*tmp;
	t_rep	*new;
	char	*tmp2;

	new = NULL;
	if (!(new = (t_rep *)malloc(sizeof(t_rep))))
		return ;
	new->name = NULL;
	new->name2 = NULL;
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	tmp2 = ft_strjoin(begin->argv, "/");
	new->name = ft_strdup(str);
	new->name2 = ft_strjoin(tmp2, new->name);
	free(tmp2);
	tmp = begin;
	if (begin == NULL)
		begin = new;
	else
	{
		while (tmp->next && ft_strcmp(tmp->name2, new->name2) < 0)
			tmp = tmp->next;
		sort_ascii(tmp, new);
	}
}
