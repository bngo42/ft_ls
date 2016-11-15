/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 19:21:02 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/06 13:18:00 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			choice_opt(t_lst **new, char *name, char *rep, char *opt)
{
	if (ft_strchr(opt, 'f'))
		create_lst_f(new, name, rep, opt);
	else if (ft_strchr(opt, 'r') == NULL && ft_strchr(opt, 't') == NULL)
		create_lst(new, name, rep, opt);
	else if (ft_strchr(opt, 'r') && ft_strchr(opt, 't') == NULL)
		create_lst_r(new, name, rep, opt);
	else if (ft_strchr(opt, 't') && ft_strchr(opt, 'r') == NULL)
		create_lst_t(new, name, rep, opt);
	else if (ft_strchr(opt, 'r') && ft_strchr(opt, 't'))
		create_lst_rt(new, name, rep, opt);
}

t_lst				*read_dir(char *rep, char *opt)
{
	struct dirent	*dir;
	DIR				*directory;
	t_lst			*new;

	errno = 0;
	new = (t_lst *)ft_memalloc(sizeof(t_lst));
	first_elem(new);
	if ((directory = opendir(rep)) == 0)
		return (0);
	while ((dir = readdir(directory)))
		choice_opt(&new, dir->d_name, rep, opt);
	if (errno != 0)
		return (0);
	closedir(directory);
	return (new);
}

t_lst				*lst(char **arg, char *opt)
{
	t_lst			*new;
	int				i;

	i = 0;
	new = (t_lst *)ft_memalloc(sizeof(t_lst));
	first_elem(new);
	while (arg[i])
	{
		choice_opt(&new, arg[i], ".", opt);
		i++;
	}
	return (new);
}
