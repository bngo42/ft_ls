/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:06:24 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/14 11:07:15 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		aff_stat(t_rep *data)
{
	struct group	*gid;

	data->mode = data->filestat.st_mode;
	file_type(data->filestat, data);
	data->mode = data->filestat.st_mode;
	ft_get_mode(data);
	ft_putchar(' ');
	ft_putnbr(data->filestat.st_nlink);
	ft_putchar(' ');
	data->user = getpwuid(data->filestat.st_uid);
	ft_putstr(data->user->pw_name);
	ft_putchar(' ');
	gid = getgrgid(data->filestat.st_gid);
	ft_putstr(gid->gr_name);
	ft_putchar(' ');
	if (S_ISBLK(data->mode) || S_ISCHR(data->mode))
	{
		ft_putnbr(data->major);
		ft_putstr(",   ");
		ft_putnbr(data->minor);
	}
	else
		ft_putnbr(data->filestat.st_size);
	ft_putchar(' ');
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
	if (S_ISBLK(data->mode))
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
	else if (S_ISLNK(data->mode))
		ft_putchar('l');
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
}
