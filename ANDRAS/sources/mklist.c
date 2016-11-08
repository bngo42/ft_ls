/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:49:50 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 10:56:48 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	int		ft_check_path(char *str)
{
	struct stat	buff;

	if (lstat(str, &buff) == -1)
		return (0);
	if (S_ISDIR(buff.st_mode) != 0)
		return (2);
	return (1);
}

static	void	ft_fill_list(char **args, t_arg **lst, int firstarg, char *opts)
{
	int			i;

	i = firstarg;
	if (firstarg == -1)
		*lst = ft_arg_create(".", NULL, NULL, NULL);
	else
	{
		if (args[0] == NULL)
			*lst = ft_arg_create(".", NULL, NULL, NULL);
		while (args[i] != NULL)
		{
			if (ft_check_path(args[i]) > 0)
				ft_arg_add(lst, args[i], NULL, opts);
			else
				ft_error(3, args, 0, i);
			i++;
		}
	}
}

t_arg			*ft_mklist(char **argv, int firstarg, char *opts)
{
	t_arg	*lst;

	lst = NULL;
	if (!argv[firstarg])
		firstarg = -1;
	ft_fill_list(argv, &lst, firstarg, opts);
	return (lst);
}
