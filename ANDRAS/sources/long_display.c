/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:29:17 by acottier          #+#    #+#             */
/*   Updated: 2016/06/27 12:11:13 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_get_data(t_arg *lst, t_sizes *data, int hidden)
{
	struct passwd	*user;
	struct group	*group;
	t_arg			*cu;

	cu = lst;
	while (cu)
	{
		if (hidden == 1 || ft_hidden(cu->path) == 0)
		{
			user = getpwuid(cu->info.st_uid);
			group = getgrgid(cu->info.st_gid);
			if (hidden == 1 || ft_hidden(cu->path) == 0)
				data->memblocks += cu->info.st_blocks;
			if (ft_strlen(user->pw_name) > data->usr_size)
				data->usr_size = ft_strlen(user->pw_name);
			if (ft_strlen(group->gr_name) > data->grp_size)
				data->grp_size = ft_strlen(group->gr_name);
			if (ft_nbrlength(cu->info.st_size) > data->file_size)
				data->file_size = ft_nbrlength(cu->info.st_size);
			if (ft_nbrlength(cu->info.st_nlink) > ft_nbrlength(data->link_size))
				data->link_size = ft_nbrlength(cu->info.st_nlink);
		}
		cu = cu->next;
	}
}

static	t_sizes	*ft_init(t_arg *list, char *opts)
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
	data->opts = opts;
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

void			ft_long_display(t_arg *lst, char *opts, int link, char *dir)
{
	t_arg			*cursor;
	t_sizes			*data;
	int				hidden;
	char			*str;

	data = NULL;
	cursor = lst;
	data = ft_init(lst, opts);
	hidden = 0;
	if (ft_opt_hidden(opts) != 0)
		hidden = 1;
	ft_get_data(lst, data, hidden);
	str = ft_strjoin("total ", ft_itoa(data->memblocks));
	if (link == -1)
		ft_putendl(str);
	free(str);
	data->file_size++;
	while (cursor)
	{
		if (hidden == 1 || ft_hidden(cursor->path) == 0)
			ft_format_long_output(cursor, data, ft_islink(cursor), dir);
		cursor = cursor->next;
	}
}
