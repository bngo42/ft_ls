/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:50 by bngo              #+#    #+#             */
/*   Updated: 2016/12/02 12:20:14 by lvalenti         ###   ########.fr       */
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
	ft_printlst(r);
	if (opt->l == 1)
		funct_l(r);
	// else if (opt->gr == 1)
	// 	funct_gr();
	// else if (opt->a == 1)
	// 	funct_a();
	// else if (opt->pr == 1)
	// 	funct_pr();
	// else if (opt->t == 1)
	// 	funct_t();
}

void		funct_l(t_rep *r)
{
	t_rep *tmp;
	t_rep *lst;

	tmp = r;
	if (!(lst = (t_rep *)malloc(sizeof(t_rep))))
		return ;
	while (tmp)
	{
		printf("%s\n", tmp->file->d_name);
		errno = 0;
		if (stat(".", tmp->filestat) < 0)
		{
			perror("STAT ERROR ");
			// printf("%u\n", tmp->filestat->st_uid);
			exit (0);
		}
		// ft_list_end(&lst, tmp);
		// printf("%u\n", tmp->filestat->st_uid);
		tmp = tmp->next;
	}
	aff_stat(r);
	printf("ok\n");
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
