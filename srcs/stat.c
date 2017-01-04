/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:06:24 by lvalenti          #+#    #+#             */
/*   Updated: 2017/01/04 18:48:07 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				aff_stat(t_rep *data, int len[6])
{
	char			*size;
	char			*major;
	char			*minor;

	display_long(data, len);
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
		show_info(size, len[3] + ((!len[7]) ? 0 : (len[4] + len[5] - 2)), 0, 1);
		free(size);
	}
	aff_stat2(data);
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

char				*get_date(t_rep *data)
{
	char			*date;
	time_t			t[3];
	char			*tmp[3];

	t[0] = data->filestat.st_mtime;
	time(&t[1]);
	t[2] = t[1] - t[0];
	if (t[2] > 15778432)
	{
		t[2] = data->filestat.st_mtime;
		tmp[2] = ctime(&t[2]);
		tmp[0] = ft_strsub(tmp[2], 4, 6);
		tmp[1] = ft_strjoin(tmp[0], " ");
		free(tmp[0]);
		tmp[0] = ft_strsub(tmp[2], 19, 5);
		date = ft_strjoin(tmp[1], tmp[0]);
		free(tmp[0]);
		free(tmp[1]);
	}
	else
	{
		date = ctime(&t[0]);
		date = modif_time(date);
	}
	return (date);
}

char				*modif_time(char *time_char)
{
	char			*rslt;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if ((rslt = (char *)malloc(sizeof(char) * 13)) == 0)
		return (NULL);
	while (time_char[j] != ' ')
		j++;
	j++;
	while (i < 12)
	{
		rslt[i] = time_char[j];
		i++;
		j++;
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
