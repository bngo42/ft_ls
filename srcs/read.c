/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:25:38 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 19:26:04 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			read_arg(char *path, t_opt *opt)
{
	t_rep		*r;

	if (path != NULL)
	{
		r = NULL;
		if (!(r = (t_rep*)ft_memalloc(sizeof(t_rep))))
			return (-1);
		if ((read_rep(r, opt, path) < 0))
			return (-1);
		r->argv = ft_strdup(path);
		assign_opt(opt, r);
		if (r->type != 1 && (closedir(r->dir) == -1))
			return (-1);
		free(r->name);
		free(r->name2);
		free(r->argv);
		free(r);
	}
	return (0);
}

int			read_rep(t_rep *r, t_opt *opt, char *path)
{
	struct stat	statfile;

	errno = 0;
	if (lstat(path, &statfile) < 0)
	{
		ft_putstr("ls: ");
		ft_putstr(path);
		ft_putstr(": ");
		perror("");
		return (-1);
	}
	if (S_ISLNK(statfile.st_mode) && opt->l == 1)
		r->type = 1;
	else if (!(r->dir = opendir(path)))
	{
		if (errno == 13)
		{
			perror("ls");
			return (-1);
		}
		else if (errno == 20)
			r->type = 1;
	}
	return (0);
}
