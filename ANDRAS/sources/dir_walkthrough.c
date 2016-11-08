/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_walkthrough.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:11:36 by acottier          #+#    #+#             */
/*   Updated: 2016/06/24 17:19:17 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	ft_print(t_ent *lst)
{
	t_ent	*cursor;

	cursor = lst;
	ft_sort_ent_list(&lst);
	while (cursor)
	{
		ft_putendl(cursor->name);
		cursor = cursor->next;
	}
}

static	void	ft_free_ent_list(t_ent *lst)
{
	t_ent	*following;
	t_ent	*cursor;

	cursor = lst;
	while (cursor)
	{
		free(cursor->name);
		cursor->name = NULL;
		following = cursor->next;
		free(cursor);
		cursor = following;
	}
}

static	t_ent	*ft_create_list(t_arg *arg)
{
	DIR				*current;
	char			*lnk;
	struct dirent	*x;
	t_ent			*lst;


	lnk = NULL;
	if (S_ISLNK(arg->info.st_mode) != 0)
		readlink(arg->path, (lnk = ft_strnew(512)), 512);
	lst = NULL;
	errno = 0;
	if (lnk)
		current = opendir(lnk);
	else
		current = opendir(arg->path);
	if (!current)
	{
		(lnk) ? ft_denied(lnk, errno) : ft_denied(arg->path, errno);
		return (NULL);
	}
	while ((x = readdir(current)) != NULL)
		(x->d_name[0] != '.') ? ft_ent_add(&lst, x->d_name, arg->path, lnk) : 0;
	closedir(current);
	ft_sort_ent_list(&lst);
	(lnk) != NULL ? free(lnk) : 0;
	return (lst);
}

static	int		ft_checkifdir(t_arg *arg)
{
	struct stat	buff;

	if (S_ISDIR(arg->info.st_mode) != 0)
		return (1);
	if (S_ISLNK(arg->info.st_mode) != 0)
	{
		stat(arg->path, &buff);
		if (S_ISDIR(buff.st_mode) != 0)
			return (1);
	}
	return (0);
}

void			ft_dir_walkthrough(t_arg *args)
{
	t_arg			*cursor;
	t_ent			*lst;

	cursor = args;
	while (cursor)
	{
		if (ft_checkifdir(cursor) == 1)
		{
			if ((lst = ft_create_list(cursor)) != NULL)
			{
				if (cursor->previous != cursor->next)
				{
					ft_putchar('\n');
					ft_putstr(ft_strcat(cursor->path, ":\n"));
				}
				ft_print(lst);
				ft_free_ent_list(lst);
			}
		}
		cursor = cursor->next;
	}
}
