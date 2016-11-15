/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_optl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:52:05 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/28 18:02:58 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void		get_year(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*time_optl;
	char			*year;
	int				j;

	j = 0;
	time_optl = ft_strsub((ctime(&(start->stat.st_mtimespec.tv_sec))), 4, 6);
	year = ft_strsub((ctime((time_t*)&(start->stat.st_mtimespec))), 20, 4);
	begin = (start->size->s_time - 1) - ft_strlen(time_optl);
	while (time_optl[j])
	{
		(*optl)[*i] = time_optl[j];
		j++;
		(*i)++;
	}
	(*optl)[(*i)++] = ' ';
	(*optl)[(*i)++] = ' ';
	j = 0;
	while (year[j])
	{
		(*optl)[(*i)++] = year[j];
		j++;
	}
	free(year);
	free(time_optl);
}

void			time_optl(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*time_optl;
	int				j;

	j = 0;
	time_optl = ft_strsub((ctime((time_t*)&(start->stat.st_mtimespec))), 4, 12);
	begin = (start->size->s_time - 1) - ft_strlen(time_optl);
	if ((time(NULL) - start->stat.st_mtime) >= 15778800
			|| start->stat.st_mtime > time(NULL))
		get_year(optl, start, i);
	else
	{
		while (time_optl[j])
		{
			(*optl)[*i] = time_optl[j];
			j++;
			(*i)++;
		}
		free(time_optl);
	}
}
