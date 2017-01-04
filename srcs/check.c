/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:58:46 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 18:00:00 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_check_letter(char arg, t_opt *opt)
{
	if (arg == 'l')
	{
		opt->count++;
		opt->l = 1;
	}
	else if (arg == 'R')
	{
		opt->count++;
		opt->gr = 1;
	}
	else if (arg == 'a')
	{
		opt->count++;
		opt->a = 1;
	}
	else if (arg == 'r')
	{
		opt->count++;
		opt->pr = 1;
	}
	else if (arg == 't')
	{
		opt->count++;
		opt->t = 1;
	}
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

char		*ft_check_arg(char **argv)
{
	char	*arg;
	int		i;
	int		j;
	int		k;
	int		bol;

	if (!(arg = (char *)ft_memalloc(sizeof(char) * 6)))
		return (NULL);
	bol = 0;
	i = 1;
	k = 0;
	while (argv[i] && !bol)
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			j++;
			while (argv[i][j] && !bol)
			{
				if (argv[i][j] == '-')
				{
					bol = 1;
					arg[k++] = '-';
				}
				else if (!ft_strchr(arg, argv[i][j]))
					arg[k++] = argv[i][j];
				j++;
			}
			argv[i] = 0;
		}
		else
			bol = 1;
		i++;
	}
	arg[k] = '\0';
	return (arg);
}
