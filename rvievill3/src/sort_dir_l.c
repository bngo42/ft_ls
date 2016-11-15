/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:15:42 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:15:43 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static char				**sort_dir(char **dir, char *opt)
{
	char				**new_dir;
	t_lst				*dir_tmp;
	int					i;
	int					size;

	i = 0;
	dir_tmp = lst(dir, opt);
	size = lst_size(dir_tmp);
	new_dir = (char **)malloc(sizeof(char *) * size + 1);
	while (dir_tmp && dir_tmp->file != NULL)
	{
		new_dir[i] = ft_strdup(dir_tmp->file);
		i++;
		dir_tmp = dir_tmp->next;
	}
	new_dir[i] = 0;
	free_tab(dir);
	return (new_dir);
}

static void				nb_dir(int *j, char **av)
{
	int					i;
	int					ret;
	struct stat			buf;

	i = 0;
	*j = 0;
	while (av[i])
	{
		ret = lstat(av[i], &buf);
		if (S_ISDIR(buf.st_mode) != 0 && ret != -1 && S_ISLNK(buf.st_mode) == 0)
			(*j)++;
		i++;
	}
}

static void				fill_dir(char **dir, char **av, int *j, int *i)
{
	struct stat			buf;
	int					ret;

	ret = lstat(av[*i], &buf);
	if ((S_ISDIR(buf.st_mode) != 0) && ret != -1
			&& S_ISLNK(buf.st_mode) == 0)
	{
		dir[*j] = ft_strdup(av[*i]);
		(*j)++;
	}
}

char					**stock_dir_l(char **av, char *opt)
{
	int					i;
	int					j;
	char				**dir;

	i = 0;
	nb_dir(&j, av);
	dir = (char **)ft_memalloc(sizeof(char *) * j + 1);
	j = 0;
	while (av[i])
	{
		fill_dir(dir, av, &j, &i);
		i++;
	}
	dir[j] = 0;
	return (sort_dir(dir, opt));
}
