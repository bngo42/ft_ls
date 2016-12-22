/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/12/22 10:08:47 by lvalenti         ###   ########.fr       */
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

t_rep		*funct_pr(t_rep *r)
{
	reverse_link(r);
	r = r->prev;
	while (r)
	{
		reverse_link(r);
		if (r->prev == NULL)
			return (r);
		r = r->prev;
	}
	return (r);
}

void		swap_link(t_rep *lst)
{
	t_rep	*tmp;

	if (!lst->prev)
	{
		tmp = lst;
		lst = lst->next;
		tmp->next = lst->next;
		lst->prev = NULL;
		lst->next = tmp;
		tmp->prev = lst;
		tmp->next->prev = tmp;
	}
	else
	{
		tmp = lst;
		lst->prev->next = lst->next;
		lst = lst->next;
		lst->prev->next = lst->next;
		lst->prev = lst->prev->prev;
		lst->next = tmp;
		tmp->prev = lst;
		if (tmp->next)
			tmp->next->prev = tmp;
	}
}

void		funct_t(t_rep *lst)
{
	t_rep			*tmp;

	tmp = lst;
	while (tmp)
	{
		errno = 0;
		if (lstat(tmp->name2, &tmp->filestat) < 0)
		{
			perror("STAT ERROR ");
			exit (0);
		}
		tmp->time_s = tmp->filestat.st_mtimespec.tv_sec;
		tmp->time_ns = tmp->filestat.st_mtimespec.tv_nsec;
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->time_s < tmp->next->time_s)
		{
			swap_link(tmp);
			tmp = lst;
		}
		else if (tmp->time_s == tmp->next->time_s)
		{
			if (tmp->time_ns < tmp->next->time_ns)
			{
				swap_link(tmp);
				tmp = lst;
			}
		}
		tmp = tmp->next;
	}
}

void		assign_opt(t_opt *opt, t_rep *r)
{
	struct dirent	*file;
	t_rep			*lst;
	t_rep			*new;

	if (!(file = readdir(r->dir)))
		return ;
	lst = (t_rep*)malloc(sizeof(t_rep));
	ft_bzero(lst, sizeof(t_rep));
	if (ft_strcmp(r->argv, ".") < 0)
	{
		ft_putendl("ok");
		lst->name2 = ft_strdup(file->d_name);
		while ((file = readdir(r->dir)))
		{
			new = (t_rep*)malloc(sizeof(t_rep));
			new->name2 = ft_strdup(file->d_name);
			add_list(&lst, new);
		}
	}
	else
	{
		lst->name2 = ft_strjoin(r->argv, "/");
		lst->name = ft_strdup(file->d_name);
		lst->name2 = ft_strjoin(lst->name2, lst->name);
		while ((file = readdir(r->dir)))
		{
			new = (t_rep*)malloc(sizeof(t_rep));
			new->name2 = ft_strjoin(r->argv, "/");
			new->name = ft_strdup(file->d_name);
			new->name2 = ft_strjoin(new->name2, new->name);
			add_list(&lst, new);
		}
	}
	// if (opt->gr == 1)
	//	funct_gr();
	if (opt->t == 1)
		funct_t(lst);
	while (lst->prev)
		lst = lst->prev;
	if (opt->pr == 1)
		lst = funct_pr(lst);
	if (opt->l == 1)
		funct_l(lst, opt);
	ft_printlst(lst, opt);
	free(lst);
}

void		funct_l(t_rep *r, t_opt *opt)
{
	t_rep	*tmp;
	t_rep	*lst;
	int		len[8];

	len[0] = 0;//LIEN
	len[1] = 0;//UID
	len[2] = 0;//GROUP
	len[3] = 0;//SIZE
	len[4] = 0;//MAJOR
	len[5] = 0;//MINOR
	len[6] = 0;//TOTAL_BLOCK
	len[7] = 0;//HAS C OR B
	tmp = r;
	if (!(lst = (t_rep *)malloc(sizeof(t_rep))))
		return ;
	while (tmp)
	{
		errno = 0;
		if (lstat(tmp->name2, &tmp->filestat) < 0)
		{
			perror("STAT ERROR ");
			exit (0);
		}
		if (opt->a == 0)
		{
			if (tmp->name[0] != '.')
				get_len(tmp, len);
		}
		else if (opt->a == 1)
			get_len(tmp, len);
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(len[6]);
	ft_putchar('\n');
	while (r)
	{
		if (opt->a == 0)
		{
			if (r->name[0] != '.')
				aff_stat(r, len);
		}
		else if (opt->a == 1)
			aff_stat(r, len);
		r = r->next;
	}
}

int		read_arg(char *path, t_opt *opt)
{
	t_rep *r;

	if (path != NULL)
	{
		if (!(r = (t_rep*)malloc(sizeof(t_rep))))
			return (-1);
		if (!(r->dir = opendir(path)))
		{
			ft_putstr("ls: ");
			ft_putstr(path);
			ft_putendl(": No such file or directory");
			return (-1);
		}
		ft_putstr(path);
		ft_putendl(": ");
		r->argv = ft_strdup(path);
		assign_opt(opt, r);
		if (!(closedir(r->dir)))
			return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char	*arg;
	t_opt	*opt;
	int		i;
	int		bol;

	i = 0;
	bol = 0;
	arg = ft_check_arg(argv);
	opt = (t_opt *)malloc(sizeof(t_opt));
	opt->l = 0;
	opt->gr = 0;
	opt->a = 0;
	opt->pr = 0;
	opt->t = 0;
	ft_check_opt(arg, opt);
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

/*
int			main(int argc, char **argv)
{
	t_rep	*r;
	char	*arg;
	t_opt	*opt;
	int		i;

	i = 0;
	arg = ft_check_arg(argv);
	opt = (t_opt *)malloc(sizeof(t_opt));
	opt->l = 0;
	opt->gr = 0;
	opt->a = 0;
	opt->pr = 0;
	opt->t = 0;
	ft_check_opt(arg, opt);
	if (!(r = (t_rep*)malloc(sizeof(t_rep))))
		return (-1);
	while (i++ < argc)
	{
		if (argv[i] != NULL)
		{
			printf("argv[%i] = [%s]\n", i, argv[i]);
			if (!(r->dir = opendir(argv[i])))
				return (-1);
			r->argv = ft_strdup(argv[i]);
			assign_opt(opt, r);
			if (!(closedir(r->dir)))
				return (-1);
		}
	}
	free(opt);
	free(r);
	return (0);
}*/
