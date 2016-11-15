/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bad_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:15:24 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:15:26 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static char			**sort_elem(char **str)
{
	int				i;
	int				j;
	char			*swap;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) < 0)
			{
				swap = str[j];
				str[j] = str[i];
				str[i] = swap;
			}
			j++;
		}
		i++;
	}
	return (str);
}

static void			nb_fail_open(char **av, int *j, int i)
{
	struct stat		buf;

	*j = 0;
	while (av[i])
	{
		if ((stat(av[i], &buf) == -1) && (lstat(av[i], &buf) != 0))
			*j = *j + 1;
		i++;
	}
}

void				fill_tab(char **av, int i, char **bad_dir, int *j)
{
	struct stat		buf;

	if ((stat(av[i], &buf) == -1) && (lstat(av[i], &buf) != 0))
	{
		bad_dir[*j] = ft_strdup(av[i]);
		*j = *j + 1;
	}
}

static char			**sort_err(char **av, char *opt)
{
	int				i;
	int				j;
	char			**bad_dir;

	i = 0;
	while (av[i] && av[i][0] == '-' && av[i][1] != '-' && av[i][1] != '\0')
		i++;
	if (av[i] && av[i][0] == '-' && av[i][1] == '-')
		i++;
	nb_fail_open(av, &j, i);
	bad_dir = (char **)ft_memalloc(sizeof(char *) * j + 1);
	j = 0;
	while (av[i])
	{
		fill_tab(av, i, bad_dir, &j);
		i++;
	}
	bad_dir[j] = 0;
	if (ft_strchr(opt, 'f') == NULL)
		bad_dir = sort_elem(bad_dir);
	return (bad_dir);
}

int					dir_error(char **av, char *opt)
{
	char			**str;
	int				i;

	i = 0;
	str = sort_err(av, opt);
	while (str[i])
	{
		ft_putstr_fd("ft_ls: ", 2);
		if (ft_strcmp(str[i], "") == 0)
		{
			ft_putstr_fd("fts_open", 2);
			ft_putendl_fd(": No such file or directory", 2);
			return (1);
		}
		else
			ft_putstr_fd(str[i], 2);
		ft_putendl_fd(": No such file or directory", 2);
		i++;
	}
	free_tab(str);
	return (0);
}
