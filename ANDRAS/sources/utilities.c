/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:07:27 by acottier          #+#    #+#             */
/*   Updated: 2016/06/24 19:01:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_hidden(const char *testpath)
{
	char	*workpath;

	if (!(ft_strrchr(testpath, '/')))
		workpath = (char *)testpath;
	else
		workpath = ft_strrchr(testpath, '/');
	if (!testpath)
		return (0);
	if (ft_strcmp(workpath, ".") == 0)
		return (2);
	else if (ft_strcmp(workpath, "..") == 0)
		return (3);
	else if (workpath[0] == '.')
		return (1);
	return (0);
}

void		ft_ent_add(t_ent **lst, char *name, char *prefix, char *lnk)
{
	t_ent	*cursor;

	if (!(*lst))
	{
		*lst = ft_ent_create(name, prefix, lnk);
		return ;
	}
	cursor = *lst;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = ft_ent_create(name, prefix, lnk);
}

t_ent		*ft_ent_create(char *name, char *prefix, char *lnk)
{
	t_ent	*lst;
	char	*fullpath;

	if (lnk)
		fullpath = ft_trijoin(lnk, "/", name);
	else
		fullpath = ft_trijoin(prefix, "/", name);
	lst = (t_ent *)malloc(sizeof(t_ent));
	lst->name = ft_strdup(name);
	lst->next = NULL;
	if (prefix)
		fullpath = ft_trijoin(prefix, "/", name);
	else
		fullpath = ft_strdup(name);
	errno = 0;
	if ((lstat(fullpath, &lst->info)) == -1)
		perror("Error when using lstat on ent_list ");
	free(fullpath);
	return (lst);
}

t_arg		*ft_arg_add(t_arg **lst, char *path, char *prefix, char *opts)
{
	t_arg	*cursor;

	if (!(*lst))
	{
		*lst = ft_arg_create(path, NULL, NULL, prefix);
		return (*lst);
	}
	if (ft_strrchr(opts, 'f') != 0)
		return (ft_arg_create(path, ft_endlist(*lst), NULL, prefix));
	cursor = *lst;
	if (ft_strcmp(cursor->path, path) > 0)
		return (ft_arg_create(path, NULL, cursor, prefix));
	while (cursor->next)
	{
		if (ft_strcmp(cursor->path, path) > 0)
			return (ft_arg_create(path, cursor->previous, cursor, prefix));
		cursor = cursor->next;
	}
	if (ft_strcmp(cursor->path, path) > 0)
		return (ft_arg_create(path, cursor->previous, cursor, prefix));
	else
		return (ft_arg_create(path, cursor, NULL, prefix));
}

t_arg		*ft_arg_create(char *path, t_arg *previous, t_arg *following,
			char *prefix)
{
	t_arg	*link;
	char	*fullpath;

	link = (t_arg *)malloc(sizeof(t_arg));
	link->path = ft_strdup(path);
	link->next = following;
	link->previous = previous;
	if (following)
		following->previous = link;
	if (previous)
		previous->next = link;
	fullpath = ft_trijoin(prefix, "/", path);
	if ((lstat(fullpath, &link->info)) == -1)
		perror("Error when using lstat on arg_list ");
	link->next = following;
	link->onext = NULL;
	link->oprev = NULL;
	link->sorted = 0;
	free(fullpath);
	return (link);
}
