/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/12/15 16:37:45 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_rep		*funct_pr(t_rep *r)
{
	t_rep	*tmpnext;
	t_rep	*tmpprev;

	tmpnext = r->next;
	tmpprev = r->prev;
	r->next = tmpprev;
	r->prev = tmpnext;
	r = r->prev;
	while (r)
	{
		tmpnext = r->next;
		tmpprev = r->prev;
		r->next = tmpprev;
		r->prev = tmpnext;
		if (r->prev == NULL)
			return (r);
		r = r->prev;
	}
	return (r);
}


void		assign_opt(t_opt *opt, t_rep *r)
{
	struct dirent	*file;
	t_rep			*lst;
	t_rep			*new;

	if (!(file = readdir(r->dir)))
		return ;
	lst = (t_rep*)malloc(sizeof(t_rep));

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
	// if (opt->t == 1)
	// 	funct_t();
	if (opt->pr == 1)
		lst = funct_pr(lst);
	if (opt->l == 1)
		funct_l(lst, opt);
	ft_printlst(lst, opt);
}

void		funct_l(t_rep *r, t_opt *opt)
{
	t_rep	*tmp;
	t_rep	*lst;
	int		len[4];

	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
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

	opt = (t_opt *)malloc(sizeof(t_opt));
	opt->l = 0;
	opt->gr = 0;
	opt->a = 0;
	opt->pr = 0;
	opt->t = 0;
	arg = ft_check_arg(argv);
	ft_check_opt(arg, opt);
	if (!(r = (t_rep*)malloc(sizeof(t_rep))))
		return (-1);
	if (!(r->dir = opendir(argv[argc - 1])))
		return (-1);
	r->argv = ft_strdup(argv[argc - 1]);
	assign_opt(opt, r);
	if (!(closedir(r->dir)))
		return (-1);
	return (0);
}
