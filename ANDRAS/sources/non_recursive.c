/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_non_recursive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:54:38 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 16:41:31 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	int		ft_nblinks(char *opts, t_arg *args)
{
	int		res;
	t_arg	*cursor;

	cursor = args;
	res = 0;
	while (cursor)
	{
		if (((ft_hidden(cursor->path) == 0) || ft_opt_hidden(opts) != 0)
			&& args->info.st_mode & S_IFLNK)
			res++;
		cursor = cursor->next;
	}
	return (res);
}

static	void	ft_directory(char *opts, t_arg *arg, int foldername, t_arg *tmp)
{
	DIR				*current;
	struct dirent	*entry;

	errno = 0;
	current = opendir(arg->path);
	if (!current)
	{
		ft_denied(arg->path, errno);
		return ;
	}
	while ((entry = readdir(current)) != NULL)
	{
		ft_arg_add(&tmp, entry->d_name, arg->path, opts);
		while (tmp->previous)
			tmp = tmp->previous;
	}
	tmp = ft_sort_display(tmp, opts, tmp);
	if (foldername == 1)
		ft_triplestr("\n", arg->path, ":\n");
	if (ft_strrchr(opts, 'l') || ft_strrchr(opts, 'g') || ft_strrchr(opts, 'o'))
		ft_long_display(tmp, opts, -1, arg->path);
	else
		ft_print_result_list(tmp, opts, arg->path);
	ft_free_list(tmp);
}

static	void	ft_link(char *opts, t_arg *arg, int foldername)
{
	struct stat	buff;

	stat(arg->path, &buff);
	if (S_ISDIR(buff.st_mode) == 0 || ft_strrchr(opts, 'l') != 0
		|| ft_strrchr(opts, 'g') || ft_strrchr(opts, 'o'))
		return ;
	ft_directory(opts, arg, foldername, NULL);
}

void			ft_non_recursive(char *opts, t_arg *args)
{
	t_arg			*cursor;
	t_arg			*tmp;
	int				links;

	tmp = NULL;
	cursor = args;
	links = ft_nblinks(opts, args);
	while (cursor)
	{
		if (S_ISLNK(cursor->info.st_mode) != 0)
		{
			if (cursor->previous == cursor->next)
				ft_link(opts, cursor, 0);
			else
				ft_link(opts, cursor, 1);
		}
		if (S_ISDIR(cursor->info.st_mode) != 0)
		{
			if (cursor->previous == cursor->next)
				ft_directory(opts, cursor, 0, NULL);
			else
				ft_directory(opts, cursor, 1, NULL);
		}
		cursor = cursor->next;
	}
}
