/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/12/13 10:59:47 by lvalenti         ###   ########.fr       */
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

t_rep	*ft_create_elem(void *data)
{
	t_rep	*list;

	list = NULL;
	list = malloc(sizeof(t_rep));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void		ft_list_push_back(t_rep **begin_list, void *data)
{
	t_rep		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

void		afficher(t_rep *list)
{
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

void		assign_opt(t_opt *opt, t_rep *r)
{
	t_rep *lst;
	int		bol;

	bol = 0;
	lst = (t_rep*)malloc(sizeof(t_rep));
	r->file = readdir(r->dir);
	printf("Lecture du dossier %s\n", r->file->d_name);
	while (!bol)
	{
		// r = lst;
		lst->file = readdir(r->dir);
		if (!lst->file)
			bol = 1;
		else
			ft_list_push_back(&r, ft_strdup(lst->file->d_name));
			// ft_list_end(&r,ft_strdup(lst->file->d_name));
		// else
	}
	// while (r->prev)
		// r = r->prev;
	// if (opt->gr == 1)
	//	funct_gr();
	// if (opt->t == 1)
	// 	funct_t();
	// exit(1);
	if (opt->pr == 1)
		r = funct_pr(r);
	if (opt->l == 1)
		funct_l(r, opt);
	if (opt->a == 1)
		funct_a(r);
		afficher(r);
	// ft_printlst(r, opt);


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
	t_rep *tmp2;

	tmp = r;
	while (tmp->next)
	{
		if (tmp->file->d_name[0] == '.')
		{
			if (!tmp->next)
			{
				if (tmp->prev)
				{
					tmp = tmp->prev;
					free(tmp->next);
					tmp->next = NULL;
				}
				else
					free(tmp);
			}
			else
			{
				tmp2 = tmp->prev;
				tmp = tmp->next;
				free(tmp->prev);
				tmp->prev = tmp2;
			}
		}
		else if (tmp && tmp->next)
			tmp = tmp->next;
	}
}

void		funct_l(t_rep *r, t_opt *opt)
{
	t_rep *tmp;
	t_rep *lst;

	tmp = r;
	if (!(lst = (t_rep *)malloc(sizeof(t_rep))))
		return ;
	printf("%d\n", opt->a);
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
			if (tmp->file->d_name[0] != '.')
				aff_stat(tmp);
			tmp = tmp->next;
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
	printf("Lecture de %s\n", argv[argc - 1]);
	assign_opt(opt, r);
	if (!(closedir(r->dir)))
		return (-1);
	return (0);
}
