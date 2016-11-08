/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:33:22 by acottier          #+#    #+#             */
/*   Updated: 2016/06/27 11:37:51 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error(int error, char **argv, char errchar, int index)
{
	ft_putstr("ft_ls: ");
	if (error == 1)
	{
		write(2, &argv[0][0], 1);
		ft_putstr_err(": No such file or directory\n");
	}
	else if (error == 2)
	{
		ft_putstr_err("illegal option -- ");
		write(2, &errchar, 1);
		write(2, "\n", 1);
		ft_putstr_err("usage: ls [-lRartfgioG] [file ...]\n");
	}
	else if (error == 3)
	{
		if (argv[index] == NULL)
			ft_putnbr(index);
		if (ft_strcmp(argv[index], "") == 0)
			ft_putstr_err("fts_open");
		else
			ft_putstr_err(argv[index]);
		ft_putstr_err(": No such file or directory\n");
	}
}
