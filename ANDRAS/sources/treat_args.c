/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:45:16 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 10:58:12 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	int			ft_firstarg(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			return (i + 1);
		else if (argv[i][0] != '-')
			return (i);
		i++;
	}
	return (-1);
}

t_arg				*ft_treat_args(char **argv, char *opts)
{
	t_arg	*arguments;

	arguments = ft_mklist(argv, ft_firstarg(argv), opts);
	while (arguments && arguments->previous)
		arguments = arguments->previous;
	return (arguments);
}
