/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_rtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:13:23 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:13:25 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		put_front(t_lst **start, t_lst *new, t_lst *begin, t_lst *prev)
{
	if (prev != NULL)
		prev->next = new;
	new->next = *start;
	*start = new;
	if (prev != NULL)
		*start = begin;
}

static void		ascii(t_lst **start, t_lst *new, t_lst *begin, t_lst *prev)
{
	while (*start && (*start)->stat.st_mtime >= new->stat.st_mtime
	&& (*start)->stat.st_mtimespec.tv_nsec == new->stat.st_mtimespec.tv_nsec
	&& ft_strcmp((*start)->file, new->file) > 0)
	{
		prev = *start;
		*start = (*start)->next;
	}
	if (*start == NULL)
	{
		prev->next = new;
		new->next = *start;
		*start = begin;
	}
	else if (ft_strcmp((*start)->file, new->file) < 0
		|| (*start)->stat.st_mtime > new->stat.st_mtime
		|| (*start)->stat.st_mtimespec.tv_nsec > new->stat.st_mtimespec.tv_nsec)
		put_front(start, new, begin, prev);
	else
	{
		new->next = (*start)->next;
		(*start)->next = new;
		*start = begin;
	}
}

static void		put_nsec(t_lst **start, t_lst *new, t_lst *begin, t_lst *prev)
{
	while (*start && (*start)->stat.st_mtime == new->stat.st_mtime
		&& (*start)->stat.st_mtimespec.tv_nsec < new->stat.st_mtimespec.tv_nsec)
	{
		prev = *start;
		*start = (*start)->next;
	}
	if (*start == NULL)
	{
		prev->next = new;
		new->next = *start;
		*start = begin;
	}
	else if ((*start)->stat.st_mtime > new->stat.st_mtime
		|| (*start)->stat.st_mtimespec.tv_nsec > new->stat.st_mtimespec.tv_nsec)
		put_front(start, new, begin, prev);
	else
		ascii(start, new, begin, prev);
}

static void		put_sec(t_lst **start, t_lst *new)
{
	t_lst		*begin;
	t_lst		*prev;

	begin = *start;
	prev = NULL;
	while (*start && (*start)->stat.st_mtime < new->stat.st_mtime)
	{
		prev = *start;
		*start = (*start)->next;
	}
	if (*start == NULL)
	{
		prev->next = new;
		new->next = *start;
		*start = begin;
	}
	else if ((*start)->stat.st_mtime > new->stat.st_mtime)
		put_front(start, new, begin, prev);
	else
		put_nsec(start, new, begin, prev);
}

void			create_lst_rt(t_lst **start, char *name, char *rep, char *opt)
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
		filling_struct(new, name, rep, opt);
		if (res != NULL)
			cmp_optl(*start, new, opt);
		if (new != NULL)
			put_sec(start, new);
	}
}
