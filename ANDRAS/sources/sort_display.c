/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 09:42:05 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 15:46:50 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	t_arg	*ft_set_start(t_arg *lst)
{
	t_arg	*start;

	start = lst;
	if (lst && start->previous)
	{
		while (start->previous)
			start = start->previous;
	}
	return (start);
}

static	t_arg	*ft_reverse_sort(t_arg *lst)
{
	t_arg	*nextswp;
	t_arg	*prevswp;

	nextswp = lst->next;
	prevswp = lst->previous;
	lst->next = prevswp;
	lst->previous = nextswp;
	lst = lst->previous;
	while (lst)
	{
		nextswp = lst->next;
		prevswp = lst->previous;
		lst->next = prevswp;
		lst->previous = nextswp;
		if (lst->previous == NULL)
			return (lst);
		lst = lst->previous;
	}
	return (lst);
}

static	t_arg	*ft_find_newer(t_arg *lst, t_arg *res)
{
	t_arg	*cursor;
	t_arg	*next;

	cursor = lst;
	while (cursor)
	{
		if (cursor->sorted == 0)
		{
			if (!res)
				res = cursor;
			else
			{
				next = ft_compare(cursor);
				if (!next)
					return (res);
				if (next->info.st_mtime == res->info.st_mtime)
					res = ft_nano(res, next);
				else if (next->info.st_mtime > res->info.st_mtime)
					res = next;
			}
		}
		cursor = cursor->next;
	}
	return (res);
}

static	t_arg	*ft_time_sort(t_arg *lst)
{
	int		sorted;
	t_arg	*history;
	t_arg	*newer;

	sorted = -1;
	newer = NULL;
	while (sorted != 1)
	{
		history = newer;
		newer = ft_find_newer(lst, NULL);
		if (newer)
		{
			newer->sorted = 1;
			newer->oprev = history;
		}
		if (!history)
			sorted = 0;
		else
			history->onext = newer;
		if (!newer)
			sorted = 1;
	}
	return (lst);
}

t_arg			*ft_sort_display(t_arg *lst, char *opts, t_arg *cursor)
{
	t_arg	*next;

	if (!cursor || ft_strrchr(opts, 'f') != 0)
		return (lst);
	if (ft_strrchr(opts, 't'))
	{
		lst = ft_time_sort(lst);
		while (cursor->previous)
			cursor = cursor->previous;
		while (cursor)
		{
			next = cursor->next;
			cursor->next = cursor->onext;
			cursor->previous = cursor->oprev;
			cursor = next;
		}
		lst = ft_set_start(lst);
	}
	if (ft_strrchr(opts, 'r'))
	{
		lst = ft_reverse_sort(lst);
		lst = ft_set_start(lst);
	}
	return (lst);
}
