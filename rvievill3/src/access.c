/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:52:14 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/10 16:17:39 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		access_specific(char **optl, t_lst *start, int *i)
{
	if (start->stat.st_mode & S_ISUID && (*optl)[3] == 'x')
		(*optl)[*i] = 's';
	if (start->stat.st_mode & S_ISUID && (*optl)[3] == '-')
		(*optl)[*i] = 'S';
	if (start->stat.st_mode & S_ISGID && (*optl)[6] == 'x')
		(*optl)[*i] = 's';
	if (start->stat.st_mode & S_ISGID && (*optl)[6] == '-')
		(*optl)[*i] = 'S';
	if (start->stat.st_mode & S_ISVTX && (*optl)[9] == 'x')
		(*optl)[*i] = 't';
	if (start->stat.st_mode & S_ISVTX && (*optl)[9] == '-')
		(*optl)[*i] = 'T';
}

static void		access_other(char **optl, t_lst *start, int *i)
{
	if (start->stat.st_mode & S_IROTH)
		(*optl)[*i] = 'r';
	else
		(*optl)[*i] = '-';
	(*i)++;
	if (start->stat.st_mode & S_IWOTH)
		(*optl)[*i] = 'w';
	else
		(*optl)[*i] = '-';
	(*i)++;
	if (start->stat.st_mode & S_IXOTH)
		(*optl)[*i] = 'x';
	else
		(*optl)[*i] = '-';
	access_specific(optl, start, i);
	(*i)++;
}

static void		access_grp(char **optl, t_lst *start, int *i)
{
	if (start->stat.st_mode & S_IRGRP)
		(*optl)[*i] = 'r';
	else
		(*optl)[*i] = '-';
	(*i)++;
	if (start->stat.st_mode & S_IWGRP)
		(*optl)[*i] = 'w';
	else
		(*optl)[*i] = '-';
	(*i)++;
	if (start->stat.st_mode & S_IXGRP)
		(*optl)[*i] = 'x';
	else
		(*optl)[*i] = '-';
	access_specific(optl, start, i);
	(*i)++;
	access_other(optl, start, i);
}

static void		access_usr(char **optl, t_lst *start, int *i)
{
	if (start->stat.st_mode & S_IRUSR)
		(*optl)[*i] = 'r';
	else
		(*optl)[*i] = '-';
	(*i)++;
	if (start->stat.st_mode & S_IWUSR)
		(*optl)[*i] = 'w';
	else
		(*optl)[*i] = '-';
	(*i)++;
	if (start->stat.st_mode & S_IXUSR)
		(*optl)[*i] = 'x';
	else
		(*optl)[*i] = '-';
	access_specific(optl, start, i);
	(*i)++;
	access_grp(optl, start, i);
}

void			access_file(char **optl, t_lst *start, int *i)
{
	if ((S_ISDIR(start->stat.st_mode) != 0))
		*optl[*i] = 'd';
	else if ((S_ISLNK(start->stat.st_mode) != 0))
		*optl[*i] = 'l';
	else if ((S_ISSOCK(start->stat.st_mode) != 0))
		*optl[*i] = 's';
	else if ((S_ISFIFO(start->stat.st_mode) != 0))
		*optl[*i] = 'p';
	else if ((S_ISBLK(start->stat.st_mode) != 0))
		*optl[*i] = 'b';
	else if ((S_ISCHR(start->stat.st_mode) != 0))
		*optl[*i] = 'c';
	else if ((S_ISREG(start->stat.st_mode) != 0))
		*optl[*i] = '-';
	(*i)++;
	access_usr(optl, start, i);
}
