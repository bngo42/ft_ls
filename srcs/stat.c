/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:06:24 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/16 14:58:48 by bngo             ###   ########.fr       */
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

void		get_len(t_rep *data, int length[6])
{
	int				len[4];
	struct passwd	*usr;
	struct group	*gid;

	len[0] = int_len(data->filestat.st_nlink);
	usr = getpwuid(data->filestat.st_uid);
	len[1] = ft_strlen(usr->pw_name);
	gid = getgrgid(data->filestat.st_gid);
	len[2] = ft_strlen(gid->gr_name);
	len[3] = int_len(data->filestat.st_size);
	length[0] = (len[0] > length[0]) ? len[0] : length[0];
	length[1] = (len[1] > length[1]) ? len[1] : length[1];
	length[2] = (len[2] > length[2]) ? len[2] : length[2];
	length[3] = (len[3] > length[3]) ? len[3] : length[3];
	length[4] += data->filestat.st_blocks;
	data->mode = data->filestat.st_mode;
	if (S_ISBLK(data->mode) || S_ISCHR(data->mode))
		length[5] = 1;
}

void		show_info(char *str, int len, int state)
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
	ft_putchar(' ');
}

void		aff_stat(t_rep *data, int len[6])
{
	struct group	*gid;
	char			*link;
	char			*size;
	
	data->mode = data->filestat.st_mode;
	file_type(data->filestat, data);
	data->mode = data->filestat.st_mode;
	ft_get_mode(data);
	link = ft_itoa(data->filestat.st_nlink);
	show_info(link, len[0], 0);
	data->user = getpwuid(data->filestat.st_uid);
	show_info(data->user->pw_name, len[1], 0);
	ft_putchar(' ');
	gid = getgrgid(data->filestat.st_gid);
	show_info(gid->gr_name, len[2], (len[5]) ? 1 : 0);
	if (len[5])
		ft_putstr("  ");
	if (S_ISBLK(data->mode) || S_ISCHR(data->mode))
	{
		ft_putnbr(data->major);
		ft_putstr(", ");
		ft_putnbr(data->minor);
		ft_putchar(' ');
	}
	else
	{
		size = ft_itoa(data->filestat.st_size);
		show_info(size, len[3], 0);
	}
	aff_stat2(data);
}

void				aff_stat2(t_rep *data)
{
	char			*file;
	time_t			t;

	t = data->filestat.st_mtime;
	file = ctime(&t);
	file = modif_time(file);
	ft_putstr(file);
	ft_putchar(' ');
	ft_putendl(data->name);
}

char				*modif_time(char *time)
{
	char			*rslt;
	int				i;

	i = 0;
	if ((rslt = (char *)malloc(sizeof(char) * 13)) == 0)
		return (NULL);
	while (*time != ' ')
		time++;
	time++;
	while (i < 12)
	{
		rslt[i] = *time;
		i++;
		time++;
	}
	rslt[12] = '\0';
	return (rslt);
}

void				file_type(struct stat filestat, t_rep *data)
{
	data->mode = filestat.st_mode & S_IFMT;
	if (S_ISLNK(data->mode))
		ft_putchar('l');
	else if (S_ISBLK(data->mode))
	{
		ft_putchar('b');
		data->major = major(data->filestat.st_rdev);
		data->minor = minor(data->filestat.st_rdev);
	}
	else if (S_ISCHR(data->mode))
	{
		ft_putchar('c');
		data->major = major(data->filestat.st_rdev);
		data->minor = minor(data->filestat.st_rdev);
	}
	else if (S_ISDIR(data->mode))
		ft_putchar('d');
	else if (S_ISFIFO(data->mode))
		ft_putchar('p');
		else if (S_ISREG(data->mode))
		ft_putchar('-');
	else if (S_ISSOCK(data->mode))
		ft_putchar('s');
}

void	ft_get_mode(t_rep *data)
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
}
