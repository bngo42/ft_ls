/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:09:47 by acottier          #+#    #+#             */
/*   Updated: 2016/06/22 15:49:44 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			inode_align(t_arg *arg)
{
	int	swap;

	swap = 0;
	while (ft_nbrlength(arg->info.st_ino) + swap++ < 7)
		ft_putstr(" ");
	ft_putnbr(arg->info.st_ino);
	ft_putstr(" ");
}

static	void	display(int show, char *opts, t_arg *cursor)
{
	int		color;
	int		inode;

	color = 0;
	inode = 0;
	if (ft_strrchr(opts, 'G'))
		color = 1;
	if (ft_strrchr(opts, 'i'))
		inode = 1;
	while (cursor)
	{
		if (show || ft_hidden(cursor->path) == 0)
		{
			if (inode)
				inode_align(cursor);
			if (color)
				ft_color_display(cursor, opts);
			else
				ft_putendl(cursor->path);
		}
		cursor = cursor->next;
	}
}

void			ft_print_result_list(t_arg *lst, char *opts, char *origin)
{
	t_arg	*cursor;
	int		show;

	cursor = lst;
	show = 0;
	if (ft_opt_hidden(opts) != 0)
		show = 1;
	if (ft_hidden(origin) % 2 == 0 || show || ft_strcmp(lst->path, ".") == 0)
		display(show, opts, cursor);
}
