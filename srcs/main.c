/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 09:49:07 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 19:23:14 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		reverse_link(t_rep *lst)
{
	t_rep	*tmpnext;
	t_rep	*tmpprev;

	tmpnext = lst->next;
	tmpprev = lst->prev;
	lst->next = tmpprev;
	lst->prev = tmpnext;
}

void		check_type(t_rep *r, t_rep *lst)
{
	struct dirent	*file;
	char			*temp;

	if (!r->type)
	{
		if (!(file = readdir(r->dir)))
			return ;
		temp = ft_strjoin(r->argv, "/");
		lst->name = ft_strdup(file->d_name);
		lst->name2 = ft_strjoin(temp, lst->name);
		free(temp);
		lst->argv = r->argv;
		while ((file = readdir(r->dir)))
			add_list(lst, file->d_name);
	}
	else
	{
		lst->name = ft_strdup(r->argv);
		lst->name2 = ft_strdup(r->argv);
	}
}

void		assign_opt_2(t_rep *r, t_opt *opt, t_rep *lst)
{
	lst->type = r->type;
	if (opt->t == 1)
		funct_t(lst);
	while (lst->prev)
		lst = lst->prev;
	if (opt->pr == 1)
		lst = funct_pr(lst);
	if (opt->l == 1)
		funct_l(lst, opt);
	ft_printlst(lst, opt);
	ft_putchar('\n');
	if (opt->gr == 1)
		funct_gr(lst, opt);
	free_lst(lst);
}

void		assign_opt(t_opt *opt, t_rep *r)
{
	t_rep			*lst;
	t_rep			*new;

	ft_memset(opt->len, 0, 8);
	lst = NULL;
	if (ft_strcmp(r->argv, "/dev/fd/4") == 0)
	{
		ft_putendl("ls: 4: directory causes a cycle");
		ft_putchar('\n');
		return ;
	}
	if (!(lst = (t_rep*)ft_memalloc(sizeof(t_rep))))
		return ;
	check_type(r, lst);
	if ((r->type == 0 && opt->nb_dir > 1) || (opt->gr == 1))
	{
		ft_putstr(r->argv);
		ft_putendl(":");
	}
	if (ft_strcmp(r->argv, "/dev/fd/3") == 0)
	{
		ft_putendl("ls: 3: Not a directory");
		return ;
	}
	assign_opt_2(r, opt, lst);
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

int			main(int argc, char **argv)
{
	char		*arg;
	t_opt		*opt;
	int			i;
	int			bol;
	struct stat statfile;

	bol = 0;
	arg = ft_check_arg(argv);
	opt = (t_opt *)ft_memalloc(sizeof(t_opt));
	opt->count = 1;
	opt->nb_ac = argc;
	ft_check_opt(arg, opt);
	opt->nb_dir = argc - opt->count;
	free(arg);
	i = 0;
	while (i++ < argc)
	{
		read_arg(argv[i], opt);
		if (argv[i])
			bol = 1;
	}
	if (!bol)
		read_arg(".", opt);
	free(opt);
	return (0);
}
