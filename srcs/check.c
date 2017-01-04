/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:58:46 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 20:15:18 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_check_letter(char arg, t_opt *opt)
{
	if (arg == 'l' || arg == 'R' || arg == 'a' || arg == 'r' || arg == 't')
		opt->count++;
	if (arg == 'l')
		opt->l = 1;
	else if (arg == 'R')
		opt->gr = 1;
	else if (arg == 'a')
		opt->a = 1;
	else if (arg == 'r')
		opt->pr = 1;
	else if (arg == 't')
		opt->t = 1;
}

int			ft_check_opt(char *arg, t_opt *opt)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		ft_check_letter(arg[i], opt);
		if (arg[i] == '-')
		{
			ft_putendl("ls: illegal option -- -");
			ft_putendl("usage: ls [-lRart] [file ...]");
			exit(0);
		}
		i++;
	}
	return (0);
}

void		init_arg(char **arg, int (*i)[4])
{
	*arg = NULL;
	if (!(*arg = (char *)ft_memalloc(sizeof(char) * 6)))
		return ;
	(*i)[0] = 0;
	(*i)[1] = 0;
	(*i)[2] = 0;
}

char		*ft_check_arg(char **argv)
{
	char	*arg;
	int		i[4];

	init_arg(&arg, &i);
	while (argv[++i[1]] && !i[0])
	{
		i[3] = 0;
		if (argv[i[1]][0] == '-')
		{
			while (argv[i[1]][++i[3]] && !i[0])
			{
				if (argv[i[1]][i[3]] == '-')
				{
					i[0] = 1;
					arg[i[2]++] = '-';
				}
				else if (!ft_strchr(arg, argv[i[1]][i[3]]))
					arg[i[2]++] = argv[i[1]][i[3]];
			}
			argv[i[1]] = 0;
		}
		else
			i[0] = 1;
	}
	return (arg);
}
