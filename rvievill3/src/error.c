/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:22:36 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/20 17:14:42 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static int			bad_option2(char **av, int i, int k)
{
	if ((av[i][0] == '-' && av[i][k] != 'l'
			&& av[i][k] != 'a' && av[i][k] != 'r' && av[i][k] != 't'
			&& av[i][k] != 'R' && av[i][k] != '-' && av[i][k] != 'f'))
		return (1);
	if (av[i][0] == '-' && av[i][k] == '-' && (av[i][k + 1] == 'a'
			|| av[i][k] == 'l' || av[i][k] == 'a' || av[i][k] == 'r'
			|| av[i][k] == 't' || av[i][k] == 'R' || av[i][k] == '-'
			|| av[i][k] == 'f'))
		return (1);
	if (av[i][0] == '-' && av[i][1] == '-' && av[i][k] != '\0' && k == 2)
		return (1);
	return (0);
}

int					end_flag(char **av, int i)
{
	if ((av[i][0] == '-' && av[i][1] == '-' && av[i][2] == '\0')
			|| (av[i][0] == '-' && av[i][1] == '\0') || av[i][0] != '-')
		return (1);
	return (0);
}

int					bad_option(char **av)
{
	int				i;
	int				k;

	i = 0;
	while (av[i])
	{
		if (end_flag(av, i) == 1)
			return (0);
		k = 1;
		while (av[i][k] && av[i][0] == '-')
		{
			if (bad_option2(av, i, k) == 1)
			{
				ft_putstr_fd("ft_ls: illegal option -- ", 2);
				ft_putchar_fd(av[i][k], 2);
				ft_putchar_fd('\n', 2);
				ft_putstr_fd("usage: ft_ls [-lRartf] [file ...]\n", 2);
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}
