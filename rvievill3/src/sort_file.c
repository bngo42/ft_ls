/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:15:48 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:15:49 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			nb_file(int *j, char **av)
{
	int				i;
	int				ret;
	struct stat		buf;

	i = 0;
	*j = 0;
	while (av[i])
	{
		ret = lstat(av[i], &buf);
		if (S_ISDIR(buf.st_mode) == 0 && (ret != -1
			|| (ret = lstat(av[i], &buf) == 0)))
			(*j)++;
		i++;
	}
}

char				**stock_file(char **av)
{
	struct stat		buf;
	int				ret;
	int				i;
	int				j;
	char			**file;

	i = 0;
	nb_file(&j, av);
	file = (char **)ft_memalloc(sizeof(char *) * j + 1);
	j = 0;
	while (av[i])
	{
		ret = stat(av[i], &buf);
		if ((S_ISDIR(buf.st_mode) == 0) && (ret != -1
			|| (lstat(av[i], &buf)) == 0))
		{
			file[j] = ft_strdup(av[i]);
			j++;
		}
		i++;
	}
	if (j == 0)
		return (NULL);
	file[j] = 0;
	return (file);
}
