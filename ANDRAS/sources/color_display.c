/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 10:36:55 by acottier          #+#    #+#             */
/*   Updated: 2016/06/21 17:35:44 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ent_color_display(t_ent *ent)
{
	if (S_ISLNK(ent->info.st_mode) != 0)
		ft_putstr("\033[0;35m");
	else if (S_ISDIR(ent->info.st_mode) != 0)
		ft_putstr("\033[7;33m");
	else if (ent->info.st_mode & S_IXUSR || ent->info.st_mode & S_IXGRP
		|| ent->info.st_mode & S_IXOTH)
		ft_putstr("\033[0;31m");
	ft_putendl(ent->name);
	ft_putstr("\033[0m");
}

void	ft_color_display(t_arg *arg, char *opts)
{
	if (S_ISLNK(arg->info.st_mode) != 0)
		ft_putstr("\033[0;35m");
	else if (S_ISDIR(arg->info.st_mode) != 0)
		ft_putstr("\033[7;33m");
	else if (arg->info.st_mode & S_IXUSR || arg->info.st_mode & S_IXGRP
		|| arg->info.st_mode & S_IXOTH)
		ft_putstr("\033[0;31m");
	if (ft_strrchr(opts, 'l') || ft_strrchr(opts, 'o') || ft_strrchr(opts, 'g'))
		ft_putstr(arg->path);
	else
		ft_putendl(arg->path);
	ft_putstr("\033[0m");
}
