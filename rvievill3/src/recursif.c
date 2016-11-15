/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:27:13 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 12:47:58 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int				size_tab(char **start)
{
	int			i;

	i = 0;
	while (start[i])
		i++;
	return (i);
}

static void		recursif_opta(char *lst_path, char *opt, t_lst *dir)
{
	char		*path_new_dir;
	t_lst		*new_dir;
	char		*first_join;

	new_dir = NULL;
	ft_putstr("\n");
	if (ft_strcmp(lst_path, "/") != 0)
		first_join = ft_strjoin(lst_path, "/");
	else
		first_join = lst_path;
	path_new_dir = ft_strjoin(first_join, dir->file);
	ft_putstr(path_new_dir);
	ft_putstr(":\n");
	if ((new_dir = read_dir(path_new_dir, opt)) != 0)
		display(opt, new_dir, b_or_c(new_dir));
	else
		permission_denied(dir->file, opt);
	while (new_dir)
	{
		if (new_dir->pos == 1 && ft_strcmp(new_dir->file, ".") != 0
				&& ft_strcmp(new_dir->file, "..") != 0)
			recursif_opta(path_new_dir, opt, new_dir);
		new_dir = new_dir->next;
	}
}

static void		recursif_without_opta(char *lst_path, char *opt, t_lst *dir)
{
	char		*path_new_dir;
	t_lst		*new_dir;
	char		*first_join;

	new_dir = NULL;
	ft_putstr("\n");
	if (ft_strcmp(lst_path, "/") != 0)
		first_join = ft_strjoin(lst_path, "/");
	else
		first_join = lst_path;
	path_new_dir = ft_strjoin(first_join, dir->file);
	ft_putstr(path_new_dir);
	ft_putstr(":\n");
	if ((new_dir = read_dir(path_new_dir, opt)) != 0)
		display(opt, new_dir, b_or_c(new_dir));
	else
		permission_denied(dir->file, opt);
	while (new_dir)
	{
		if (new_dir->pos == 1 && new_dir->file[0] != '.')
			recursif_without_opta(path_new_dir, opt, new_dir);
		new_dir = new_dir->next;
	}
}

static void		search_dir(char *lst_path, char *opt, t_lst *dir)
{
	if (ft_strchr(opt, 'R'))
	{
		if (ft_strchr(opt, 'a') == NULL)
		{
			while (dir)
			{
				if (dir->pos == 1 && dir->file[0] != '.')
					recursif_without_opta(lst_path, opt, dir);
				dir = dir->next;
			}
		}
		else
		{
			while (dir)
			{
				if (dir->pos == 1 && ft_strcmp(dir->file, ".") != 0
						&& ft_strcmp(dir->file, "..") != 0)
					recursif_opta(lst_path, opt, dir);
				dir = dir->next;
			}
		}
	}
}

void			riffle_path(char *opt, char **lst_path, char **file, int path)
{
	t_lst		*dir;
	t_lst		*tmp3;
	int			i;

	i = 0;
	tmp3 = NULL;
	while (lst_path[i])
	{
		display_first_dir(lst_path[i], path, file);
		if ((dir = read_dir(lst_path[i], opt)) != 0)
		{
			tmp3 = dir;
			display(opt, dir, b_or_c(tmp3));
			search_dir(lst_path[i], opt, dir);
		}
		else
			permission_denied(lst_path[i], opt);
		if (lst_path[i + 1])
			ft_putstr("\n");
		i++;
	}
	free_lst(tmp3);
}
