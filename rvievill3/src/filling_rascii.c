/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_rascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:18:51 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 15:59:46 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			inser_rascii(t_lst **start, t_lst *new)
{
	t_lst		*tmp;
	t_lst		*tmp2;

	if (ft_strcmp((*start)->file, new->file) >= 0)
	{
		tmp = *start;
		while (*start && ft_strcmp((*start)->file, new->file) >= 0)
		{
			tmp2 = *start;
			*start = (*start)->next;
		}
		new->next = tmp2->next;
		tmp2->next = new;
		*start = tmp;
	}
	else
	{
		new->next = *start;
		*start = new;
	}
}

void			create_lst_r(t_lst **start, char *name, char *rep, char *opt)
{
	t_lst		*new;
	char		*res;

	res = ft_strchr(opt, 'l');
	if ((*start)->pos == -1)
	{
		filling_struct(*start, name, rep, opt);
		if (res != NULL)
		{
			first_size(*start);
			filling_size(*start);
		}
	}
	else
	{
		new = (t_lst *)ft_memalloc(sizeof(t_lst));
		if (new == NULL && start == NULL)
			*start = new;
		filling_struct(new, name, rep, opt);
		if (res != NULL)
			cmp_optl(*start, new, opt);
		if (new != NULL)
			inser_rascii(start, new);
	}
}
