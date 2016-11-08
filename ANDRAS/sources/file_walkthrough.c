/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_walkthrough.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:56:10 by acottier          #+#    #+#             */
/*   Updated: 2016/06/24 16:40:49 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	int		ft_isfile(t_arg *arg, char *opts)
{
	struct stat	buff;

	if (S_ISDIR(arg->info.st_mode) != 0)
		return (0);
	if (S_ISLNK(arg->info.st_mode) != 0)
	{
		if (ft_strrchr(opts, 'l') != 0 || ft_strrchr(opts, 'g') != 0
				|| ft_strrchr(opts, 'o') != 0)
			return (1);
		stat(arg->path, &buff);
		if (S_ISDIR(buff.st_mode) != 0)
			return (0);
		return (1);
	}
	return (1);
}

static	t_sizes	*ft_init(t_arg *list)
{
	t_arg			*cursor;
	t_sizes			*data;

	data = (t_sizes*)malloc(sizeof(t_sizes));
	data->memblocks = 0;
	data->usr_size = 0;
	data->grp_size = 0;
	data->file_size = 0;
	data->link_size = 0;
	data->minmaj = 0;
	cursor = list;
	while (cursor)
	{
		if (S_ISBLK(cursor->info.st_mode) != 0
				|| S_ISCHR(cursor->info.st_mode) != 0)
			data->minmaj = 1;
		cursor = cursor->next;
	}
	return (data);
}

static	void	display(t_arg *arg, char *opts)
{
	if (ft_strrchr(opts, 'G'))
		ft_color_display(arg, opts);
	else
	{
		if (ft_strrchr(opts, 'i'))
		{
			ft_putnbr(arg->info.st_ino);
			ft_putstr(" ");
		}
		ft_putendl(arg->path);
	}
}

void			ft_file_walkthrough(t_arg *arg, char *opts)
{
	t_arg		*cur;
	int			length;
	t_sizes		*data;

	data = ft_init(arg);
	cur = arg;
	length = 0;
	while (cur)
	{
		if (ft_isfile(cur, opts) == 1)
		{
			if (ft_strrchr(opts, 'l') != 0 || ft_strrchr(opts, 'g') != 0
					|| ft_strrchr(opts, 'o') != 0)
				ft_format_long_output(cur, data, ft_islink(cur), arg->path);
			else
				display(cur, opts);
		}
		cur = cur->next;
	}
}
