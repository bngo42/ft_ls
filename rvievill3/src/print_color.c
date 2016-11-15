/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:15:06 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:15:07 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		print_color(t_lst *start, char *opt)
{
	if (S_ISLNK(start->stat.st_mode) != 0)
		ft_putstr("\033[35m");
	else if (S_ISDIR(start->stat.st_mode) != 0)
		ft_putstr("\033[36m");
	else if (S_ISCHR(start->stat.st_mode) != 0)
		ft_putstr("\033[7m\033[33m");
	else if (S_ISBLK(start->stat.st_mode) != 0)
		ft_putstr("\033[7m\033[36m");
	else if (S_ISSOCK(start->stat.st_mode) != 0)
		ft_putstr("\033[7m\033[34m");
	else if (S_ISFIFO(start->stat.st_mode) != 0)
		ft_putstr("\033[33m");
	else if (S_IXUSR & start->stat.st_mode || S_IXGRP & start->stat.st_mode
			|| S_IXOTH & start->stat.st_mode)
		ft_putstr("\033[31m");
	if (S_ISLNK(start->stat.st_mode) != 0 && ft_strchr(opt, 'l'))
		ft_putstr(start->file);
	else
		ft_putendl(start->file);
	ft_putstr("\033[0m");
}
