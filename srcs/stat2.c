/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:43:07 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 18:47:12 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			int_len(int nb)
{
	int len;

	len = 0;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len + 1);
}

void		get_len(t_rep *data, t_opt *opt)
{
	int				len[6];
	struct passwd	*usr;
	struct group	*gid;

	usr = NULL;
	len[0] = int_len(data->filestat.st_nlink);
	usr = getpwuid(data->filestat.st_uid);
	len[1] = ft_strlen(usr->pw_name);
	gid = getgrgid(data->filestat.st_gid);
	len[2] = ft_strlen(gid->gr_name);
	len[3] = int_len(data->filestat.st_size);
	data->mode = data->filestat.st_mode;
	if (S_ISBLK(data->mode) || S_ISCHR(data->mode))
	{
		opt->len[7] = 1;
		len[4] = int_len(major(data->filestat.st_rdev));
		len[5] = int_len(minor(data->filestat.st_rdev));
		opt->len[4] = (len[4] > opt->len[4]) ? len[4] : opt->len[4];
		opt->len[5] = (len[5] > opt->len[5]) ? len[5] : opt->len[5];
	}
	opt->len[0] = (len[0] > opt->len[0]) ? len[0] : opt->len[0];
	opt->len[1] = (len[1] > opt->len[1]) ? len[1] : opt->len[1];
	opt->len[2] = (len[2] > opt->len[2]) ? len[2] : opt->len[2];
	opt->len[3] = (len[3] > opt->len[3]) ? len[3] : opt->len[3];
	opt->len[6] += data->filestat.st_blocks;
}

void		show_info(char *str, int len, int state, int state2)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(str);
	if (state)
		ft_putstr(str);
	if (length < len)
	{
		while (i++ < (len - length))
			ft_putchar(' ');
	}
	if (!state)
		ft_putstr(str);
	if (state2)
		ft_putchar(' ');
}

void		display_long(t_rep *data, int len[6])
{
	char			*link;
	struct group	*gid;

	data->mode = data->filestat.st_mode;
	file_type(data->filestat, data);
	data->mode = data->filestat.st_mode;
	ft_get_mode(data);
	link = ft_itoa(data->filestat.st_nlink);
	show_info(link, len[0], 0, 1);
	free(link);
	data->user = getpwuid(data->filestat.st_uid);
	show_info(data->user->pw_name, len[1], 1, 1);
	ft_putchar(' ');
	gid = getgrgid(data->filestat.st_gid);
	show_info(gid->gr_name, len[2], 1, 1);
	ft_putchar(' ');
}

void		ft_get_mode(t_rep *data)
{
	char	*mod;

	mod = ft_strdup("---------");
	if (data->mode & S_IRUSR)
		mod[0] = 'r';
	if (data->mode & S_IWUSR)
		mod[1] = 'w';
	if (data->mode & S_IXUSR)
		mod[2] = 'x';
	if (data->mode & S_IRGRP)
		mod[3] = 'r';
	if (data->mode & S_IWGRP)
		mod[4] = 'w';
	if (data->mode & S_IXGRP)
		mod[5] = 'x';
	if (data->mode & S_IROTH)
		mod[6] = 'r';
	if (data->mode & S_IWOTH)
		mod[7] = 'w';
	if (data->mode & S_IXOTH)
		mod[8] = 'x';
	ft_putstr(mod);
	ft_putstr("  ");
	free(mod);
}
