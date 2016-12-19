/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:58:46 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/19 11:27:31 by lvalenti         ###   ########.fr       */
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
	ft_bzero(arg, sizeof(char));
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
