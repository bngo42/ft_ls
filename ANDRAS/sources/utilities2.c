/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 11:11:58 by acottier          #+#    #+#             */
/*   Updated: 2016/06/13 14:28:23 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_arg			*ft_compare(t_arg *lst)
{
	t_arg	*cursor;

	cursor = lst;
	while (cursor)
	{
		if (cursor->sorted == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

int				ft_islink(t_arg *arg)
{
	if (S_ISLNK(arg->info.st_mode) != 0)
		return (1);
	return (0);
}

static	char	ft_define_type(t_arg *link)
{
	if (S_ISREG(link->info.st_mode) != 0)
		return ('-');
	else if (S_ISDIR(link->info.st_mode) != 0)
		return ('d');
	else if (S_ISLNK(link->info.st_mode) != 0)
		return ('l');
	else if (S_ISFIFO(link->info.st_mode) != 0)
		return ('p');
	else if (S_ISBLK(link->info.st_mode) != 0)
		return ('b');
	else if (S_ISCHR(link->info.st_mode) != 0)
		return ('c');
	else if (S_ISSOCK(link->info.st_mode) != 0)
		return ('s');
	return ('#');
}

static	void	ft_permissions_next(t_arg *link, char *str)
{
	if (link->info.st_mode & S_ISUID && str[3] == 'x')
		str[3] = 's';
	if (link->info.st_mode & S_ISUID && str[3] == '-')
		str[3] = 'S';
	if (link->info.st_mode & S_ISGID && str[6] == 'x')
		str[6] = 's';
	if (link->info.st_mode & S_ISGID && str[6] == '-')
		str[6] = 'S';
	if (link->info.st_mode & S_ISVTX && str[9] == 'x')
		str[9] = 't';
	if (link->info.st_mode & S_ISVTX && str[9] == '-')
		str[9] = 'T';
	ft_putstr(str);
	free(str);
}

void			ft_permissions(t_arg *link)
{
	char	*str;

	str = ft_strdup("----------  ");
	str[0] = ft_define_type(link);
	if (link->info.st_mode & S_IRUSR)
		str[1] = 'r';
	if (link->info.st_mode & S_IWUSR)
		str[2] = 'w';
	if (link->info.st_mode & S_IXUSR)
		str[3] = 'x';
	if (link->info.st_mode & S_IRGRP)
		str[4] = 'r';
	if (link->info.st_mode & S_IWGRP)
		str[5] = 'w';
	if (link->info.st_mode & S_IXGRP)
		str[6] = 'x';
	if (link->info.st_mode & S_IROTH)
		str[7] = 'r';
	if (link->info.st_mode & S_IWOTH)
		str[8] = 'w';
	if (link->info.st_mode & S_IXOTH)
		str[9] = 'x';
	ft_permissions_next(link, str);
}
