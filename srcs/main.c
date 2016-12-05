/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/12/05 11:00:39 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_check_opt(char *arg, t_opt *opt)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'l')
			opt->l = 1;
		else if (arg[i] == 'R')
			opt->gr = 1;
		else if (arg[i] == 'a')
			opt->a = 1;
		else if (arg[i] == 'r')
			opt->pr = 1;
		else if (arg[i] == 't')
			opt->t = 1;
		else
		{
			ft_putendl("MESSAGE A LA CON");
			exit (0);
		}
		i++;
	}
	return (0);
}

char		*ft_check_arg(char **argv)
{
	char *arg;
	int i;
	int j;
	int k;

	if (!(arg = (char*)malloc(sizeof(char) * 6)))
		return (NULL);
	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			j++;
			while (argv[i][j])
			{
				if (argv[i][j] == '-')
				{
					ft_putendl("Erreur\n");
					exit(0);
				}
				else if (!ft_strchr(arg, argv[i][j]))
					arg[k++] = argv[i][j];
				j++;
			}
		}
		i++;
	}
	arg[k] = '\0';
	printf("arg = %s\n", arg);
	return (arg);
}

void		assign_opt(t_opt *opt, t_rep *r)
{
	t_rep *lst;
	int		bol;

	bol = 0;
	r->file = readdir(r->dir);
	while (!bol)
	{
		lst = (t_rep*)malloc(sizeof(t_rep));
		lst->file = readdir(r->dir);
		if (lst->file)
			ft_list_end(&r, lst);
		else
			bol = 1;
	}
	if (opt->a == 1)
		funct_a(r);
	if (opt->l == 1)
		funct_l(r);
	ft_printlst(r, opt);
	// else if (opt->gr == 1)
	// 	funct_gr();
	// else if (opt->a == 1)
	// 	funct_a();
	// else if (opt->pr == 1)
	// 	funct_pr();
	// else if (opt->t == 1)
	// 	funct_t();
}
char    *ft_search(const char *s, int c)
{
	int             a;
	char            b;
	char            *d;
	a = 0;
	b = (char)c;
	d = (char *)s;
	if (d[a] == b)
		return (&d[a]);
	return (0);
}

t_rep		*sup_head(t_rep *rep)
{
	t_rep *tmp;

	tmp = rep->next;
	free(rep);
	return (tmp);
}

void		funct_a(t_rep *r)
{
	t_rep *tmp;

	while (r->next)
	{
		if (r->file->d_name[0] == '.')
		{
			if (!r->next)
			{
				if (r->prev)
				{
					r = r->prev;
					free(r->next);
					r->next = NULL;
				}
				else
					free(r);
			}
			else
			{
				tmp = r->prev;
				r = r->next;
				free(r->prev);
				r->prev = tmp;
			}
		}
		else if (r && r->next)
			r = r->next;
	}
}

void		funct_l(t_rep *r)
{
	t_rep *tmp;
	t_rep *lst;
	t_opt *opt;

	tmp = r;
	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
		return ;
	if (!(lst = (t_rep *)malloc(sizeof(t_rep))))
		return ;
	while (tmp)
	{
		errno = 0;
		if (stat(tmp->file->d_name, &tmp->filestat) < 0)
		{
			perror("STAT ERROR ");
			exit (0);
		}
		if (opt->a == 0)
		{
			if (tmp->file->d_name[0] == '.')
				tmp = tmp->next;
			else
			{
				aff_stat(tmp);
				// ft_putendl(lst->file->d_name);
				tmp = tmp->next;
			}
		}
		else if (opt->a == 1)
		{
			aff_stat(tmp);
			tmp = tmp->next;
		}
	}
}

int			main(int argc, char **argv)
{
	t_rep	*r;
	char	*arg;
	t_opt	*opt;

	opt = (t_opt *)malloc(sizeof(t_opt));
	arg = ft_check_arg(argv);
	ft_check_opt(arg, opt);
	if (!(r = (t_rep*)malloc(sizeof(t_rep))))
		return (-1);
	if (!(r->dir = opendir(argv[argc - 1])))
		return (-1);
	assign_opt(opt, r);
	if (!(closedir(r->dir)))
		return (-1);
	return (0);
}
