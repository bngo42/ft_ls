/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 08:30:30 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 16:42:19 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	t_arg	*ft_set_start(t_arg *list)
{
	t_arg	*start;

	start = list;
	if (list && start->previous)
	{
		while (start->previous)
			start = start->previous;
	}
	return (start);
}

static	void	display(t_arg *lst, char *opts, char *path, char *prefix)
{
	t_arg	*cursor;

	cursor = lst;
	if (lst)
	{
		lst = ft_set_start(lst);
		lst = ft_sort_display(lst, opts, lst);
	}
	if (prefix)
	{
		ft_doublestr("\n", path);
		ft_putendl(":");
	}
	if (lst && (ft_strrchr(opts, 'l') || ft_strrchr(opts, 'o') 
				|| ft_strrchr(opts, 'g')))
		ft_long_display(lst, opts, 1, prefix);
	else if (lst)
		ft_print_result_list(lst, opts, prefix);
}

static	t_arg	*ft_fill_print(char *path, char *opts, char *prefix)
{
	t_arg			*lst;
	t_arg			*cursor;
	DIR				*current;
	struct dirent	*x;

	lst = NULL;
	errno = 0;
	if ((current = opendir(path)) == NULL)
	{
		display(NULL, opts, path, prefix);
		ft_denied(path, errno);
		return (NULL);
	}
	while ((x = readdir(current)) != NULL)
	{
		if (ft_hidden(x->d_name) == 0 || ft_opt_hidden(opts) != 0)
		{
			lst = ft_set_start(lst);
			cursor = ft_arg_add(&lst, x->d_name, path, opts);
		}
	}
	closedir(current);
	display(lst, opts, path, prefix);
	return (ft_set_start(lst));
}

void			ft_recursive(char *opts, t_arg *args, char *prefix)
{
	t_arg	*cursor;
	t_arg	*new;
	char	*tmp;

	new = NULL;
	cursor = args;
	while (cursor)
	{
		if (S_ISDIR(cursor->info.st_mode) != 0)
		{
			if (ft_hidden(cursor->path) == 0
				|| (ft_hidden(cursor->path) == 1 && ft_opt_hidden(opts) != 0)
				|| (ft_hidden(cursor->path) > 1 && !prefix))
			{
				tmp = ft_trijoin(prefix, "/", cursor->path);
				new = ft_fill_print(tmp, opts, prefix);
				if (new)
					ft_recursive(opts, new, tmp);
				new = ft_set_start(new);
				ft_free_list(new);
				free(tmp);
			}
		}
		cursor = cursor->next;
	}
}
