/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:46:54 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 16:00:24 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int						lst_size(t_lst *start)
{
	int					i;

	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

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
		ret = stat(av[i], &buf);
		if (S_ISDIR(buf.st_mode) != 0 && ret != -1)
			(*j)++;
		i++;
	}
}

char					**stock_dir(char **av, char *opt)
{
	struct stat			buf;
	int					ret;
	int					i;
	int					j;
	char				**dir;

	i = 0;
	nb_dir(&j, av);
	dir = (char **)ft_memalloc(sizeof(char *) * j + 1);
	j = 0;
	while (av[i])
	{
		ret = stat(av[i], &buf);
		if ((S_ISDIR(buf.st_mode) != 0) && ret != -1)
			dir[j++] = ft_strdup(av[i]);
		i++;
	}
	dir[j] = 0;
	return (sort_dir(dir, opt));
}
