/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_long_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:50:34 by acottier          #+#    #+#             */
/*   Updated: 2016/06/27 12:14:29 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	char	*ft_get_time_format(time_t date)
{
	char	*timer;
	char	*swap;
	char	*swap2;
	char	*res;
	time_t	t;

	timer = ctime(&date);
	t = 0;
	if ((date + 15552000) < time(&t) || date > time(&t))
	{
		swap = ft_strsub(timer, 4, 7);
		swap2 = ft_strsub(timer, 20, 4);
		res = (ft_trijoin(swap, " ", swap2));
		free(swap);
		free(swap2);
		return (res);
	}
	else
		return (ft_strsub(timer, 4, 12));
}

static	void	ft_time_link(t_arg *lst, int link, char *dir, char *opts)
{
	char	*time;
	char	*fullpath;
	char	linkname[513];

	ft_bzero(linkname, 513);
	time = ft_get_time_format(lst->info.st_mtime);
	ft_putstr(time);
	free(time);
	ft_putstr(" ");
	if (ft_strrchr(opts, 'G'))
		ft_color_display(lst, opts);
	else
		ft_putstr(lst->path);
	if (link == 1)
	{
		fullpath = ft_trijoin(dir, "/", lst->path);
		readlink(fullpath, linkname, 512);
		free(fullpath);
		ft_doublestr(" -> ", linkname);
	}
	ft_putstr("\n");
}

static	void	ft_major_minor(t_arg *lst, t_sizes *data, char *group)
{
	unsigned int	maj;
	unsigned int	min;
	int				limit;
	int				swap;

	maj = major(lst->info.st_rdev);
	min = minor(lst->info.st_rdev);
	swap = 0;
	limit = (int)data->grp_size - ft_strlen(group);
	while (ft_nbrlength(maj) + swap++ < 5 + limit)
		ft_putstr(" ");
	ft_putstr(" ");
	ft_doublestr(ft_itoa(maj), ",");
	swap = 0;
	while (ft_nbrlength(min) + swap++ < 4)
		ft_putstr(" ");
	ft_putstr(" ");
	ft_doublestr(ft_itoa(min), " ");
}

static	void	ft_grp_size(t_arg *lst, t_sizes *data)
{
	struct group	*group;
	int				swap;

	group = getgrgid(lst->info.st_gid);
	if (ft_strrchr(data->opts, 'o') == 0)
		ft_putstr(group->gr_name);
	if (S_ISBLK(lst->info.st_mode) != 0 || S_ISCHR(lst->info.st_mode) != 0)
		return (ft_major_minor(lst, data, group->gr_name));
	if (ft_strrchr(data->opts, 'o') == 0)
	{
		swap = 0;
		while (ft_strlen(group->gr_name) + swap++ < data->grp_size)
			ft_putstr(" ");
	}
	swap = 0;
	if (data->minmaj == 1)
		ft_putstr("         ");
	while (ft_nbrlength(lst->info.st_size) + swap++ < data->file_size)
		ft_putstr(" ");
	ft_putstr(" ");
	ft_doublestr(ft_itoa(lst->info.st_size), " ");
}

void			ft_format_long_output(t_arg *lst, t_sizes *data, int link,
				char *dir)
{
	int				linksize;
	struct passwd	*user;
	int				swap;

	if (ft_strrchr(data->opts, 'i') != 0)
		inode_align(lst);
	ft_permissions(lst);
	user = getpwuid(lst->info.st_uid);
	swap = 0;
	linksize = ft_nbrlength(lst->info.st_nlink);
	while ((linksize + swap++) < data->link_size)
		ft_putstr(" ");
	ft_doublestr(ft_itoa(lst->info.st_nlink), " ");
	if (ft_strrchr(data->opts, 'g') == 0)
	{
		ft_putstr(user->pw_name);
		ft_strrchr(data->opts, 'o') ? 0 : ft_putstr("  ");
		swap = 0;
		while (ft_strlen(user->pw_name) + swap++ < data->usr_size)
			ft_putstr(" ");
	}
	ft_grp_size(lst, data);
	ft_time_link(lst, link, dir, data->opts);
}
