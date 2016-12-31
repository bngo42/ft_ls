/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:58:46 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/31 12:00:10 by lvalenti         ###   ########.fr       */
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
		{
			opt->count = 2;
			opt->l = 1;
		}
		else if (arg[i] == 'R')
		{
			opt->count = 2;
			opt->gr = 1;
		}
		else if (arg[i] == 'a')
		{
			opt->count = 2;
			opt->a = 1;
		}
		else if (arg[i] == 'r')
		{
			opt->count = 2;
			opt->pr = 1;
		}
		else if (arg[i] == 't')
		{
			opt->count = 2;
			opt->t = 1;
		}
		else
		{
			ft_putstr("ls: ");
			ft_putstr(arg);
			ft_putendl(": No such file or directory");
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
	int	bol;

	if (!(arg = (char*)malloc(sizeof(char) * 6)))
		return (NULL);
	ft_bzero(arg, sizeof(char));
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
					bol = 1;
				else if (!ft_strchr(arg, argv[i][j]))
					arg[k++] = argv[i][j];
				j++;
			}
			argv[i] = 0;
		}
		i++;
	}
	arg[k] = '\0';
	return (arg);
}
