/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 21:24:25 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 20:50:40 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				first_elem(t_lst *new)
{
	new->pos = -1;
	new->error = 0;
	new->next = NULL;
}

static void			type_file(t_lst *new, struct stat buf)
{
	if ((S_ISDIR(buf.st_mode) != 0))
		new->type = 'd';
	else if (S_ISLNK(buf.st_mode) != 0)
		new->type = 'l';
	else
		new->type = 'f';
}

static void			filling_stat(t_lst *new, struct stat buf)
{
	long long int	size;

	new->stat = buf;
	size = new->stat.st_size;
	new->major = major(new->stat.st_rdev);
	new->minor = minor(new->stat.st_rdev);
	if (S_ISLNK(buf.st_mode))
	{
		if (size == 0)
			size = 5;
		new->link = (char *)malloc(sizeof(char) * size);
		readlink(new->dir, new->link, size);
		if (new->link[0] == '\0')
			readlink(new->file, new->link, size);
		new->link[size] = '\0';
	}
}

void				filling_struct(t_lst *new, char *name, char *rep, char *opt)
{
	struct stat		buf;
	int				ret;

	new->dir = ft_strdup(rep);
	new->dir = ft_strjoin(new->dir, "/");
	new->file = ft_strdup(name);
	new->dir = ft_strjoin(new->dir, new->file);
	if ((ret = lstat(new->dir, &buf) != -1)
			|| (ret = stat(new->dir, &buf) != -1))
		type_file(new, buf);
	new->pos = (new->type == 'd' ? 1 : 0);
	if ((ret = lstat(new->dir, &buf)) != -1
			|| (ret = lstat(new->file, &buf) != -1))
		filling_stat(new, buf);
	else
		permission_denied(new->file, opt);
	if (ft_strcmp(new->file, ".") == 0 || ft_strcmp(new->file, "..") == 0)
		new->pos = 0;
	new->next = NULL;
}
