/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:06:24 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 13:05:09 by lvalenti         ###   ########.fr       */
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

void		aff_stat(t_rep *data, int len[6])
{
	struct group	*gid;
	char			*link;//Ces chaines de caractere
	char			*size;//peuvent etre remplacee par
	char			*major;//un seul char* tmp; mais il faut
	char			*minor;//penser a le free a chaque fois

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
	if (len[7])
		ft_putchar(' ');
	if (S_ISBLK(data->mode) || S_ISCHR(data->mode))
	{
		major = ft_itoa(data->major);
		show_info(major, len[4], 0, 0);
		free(major);
		ft_putstr(", ");
		minor = ft_itoa(data->minor);
		show_info(minor, len[5], 0, 1);
		free(minor);
	}
	else
	{
		size = ft_itoa(data->filestat.st_size);
		show_info(size, len[3] + ((!len[7]) ? 0 : (len[4] + len[5] - 2)), 0 , 1);
		free(size);
	}
	aff_stat2(data);
}

char				*get_date(t_rep *data)
{
	char			*date;
	char			*date_tmp;
	time_t			t;
	time_t			t_now;
	time_t			diff;
	char			*lol[2];

	date = NULL;
	if (!(date = (char *)malloc(sizeof(char))))
		return NULL;
	t = data->filestat.st_mtime;
	time(&t_now);
	diff = t_now - t;
	if (diff > 15778432)
	{
		diff = data->filestat.st_mtime;
		date_tmp = ctime(&diff);
		lol[0] = ft_strsub(date_tmp, 4, 6);
		lol[1] = ft_strjoin(lol[0], " ");
		free(lol[0]);
		date = ft_strjoin(lol[1], (lol[0] = ft_strsub(date_tmp, 19, 5)));
		free(lol[0]);
		free(lol[1]);
	}
	else
	{
		date = ctime(&t);
		date = modif_time(date);
	}
	return (date);
}

void				aff_stat2(t_rep *data)
{
	char			*date;
	char			buf[1024];
	ssize_t			i;

	date = get_date(data);
	ft_putstr(date);
	ft_putchar(' ');
	free(date);
	if (S_ISLNK(data->mode))
	{
		ft_putstr(data->name);
		ft_putstr(" -> ");
		errno = 0;
		if ((i = readlink(data->name2, buf, 1023)) < 0)
			perror("ls :\n");
		else
		{
			buf[i] = '\0';
			ft_putendl(buf);
		}
	}
	else
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
	free(mod);
}
