/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/12/20 17:44:35 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		swap_link(t_rep *lst)
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
	swap_link(r);
	r = r->prev;
	while (r)
	{
		swap_link(r);
		if (r->prev == NULL)
			return (r);
		r = r->prev;
	}
	return (r);
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
	while (lst && lst->next)
	{
		printf("current:%i next:%i\n", lst->time_s, lst->next->time_s);
		if (lst->time_s < lst->next->time_s)
		{
			swap_link(lst);
		}
		// printf("current:%i next:%i\n", lst->time_s, lst->next->time_s);
		// else if (lst->time_s == lst->next->time_s)
		lst = lst->next;
	}
	ft_putstr("0000000000");
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

int			main(int argc, char **argv)
{
	t_rep	*r;
	char	*arg;
	t_opt	*opt;

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
	if (!(r->dir = opendir(argv[argc - 1])))
		return (-1);
	r->argv = ft_strdup(argv[argc - 1]);
	assign_opt(opt, r);
	if (!(closedir(r->dir)))
		return (-1);
	free(opt);
	free(r);
	return (0);
}
