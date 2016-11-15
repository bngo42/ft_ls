/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lnk_size_optl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:45:58 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/06 16:26:11 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				lnk(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*lnk;
	int				j;

	j = 0;
	lnk = ft_itoa(start->stat.st_nlink);
	begin = start->size->s_lnk - (int)ft_strlen(lnk);
	while (j < begin)
	{
		(*optl)[*i] = ' ';
		(*i)++;
		j++;
	}
	j = 0;
	while (lnk[j])
	{
		(*optl)[(*i)++] = lnk[j];
		j++;
	}
	free(lnk);
}

static void			get_min(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*minor;
	int				j;

	j = 0;
	minor = ft_itoa(start->minor);
	begin = start->size->s_maj_min - (int)ft_strlen(minor);
	while (j < begin)
	{
		(*optl)[*i] = ' ';
		(*i)++;
		j++;
	}
	j = 0;
	while (minor[j])
	{
		(*optl)[(*i)++] = minor[j];
		j++;
	}
	free(minor);
}

static void			get_maj_min(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*major;
	int				j;

	j = 0;
	major = ft_itoa(start->major);
	begin = start->size->s_maj_min - (int)ft_strlen(major);
	while (j < begin)
	{
		(*optl)[*i] = ' ';
		(*i)++;
		j++;
	}
	j = 0;
	while (major[j])
	{
		(*optl)[(*i)++] = major[j];
		j++;
	}
	(*optl)[(*i)++] = ',';
	(*optl)[(*i)++] = ' ';
	free(major);
	get_min(optl, start, i);
}

void				size(char **optl, t_lst *start, int *i, int exist)
{
	int				begin;
	char			*size;
	int				j;

	j = 0;
	size = ft_itoa((size_t)start->stat.st_size);
	begin = start->size->s_size - (int)ft_strlen(size);
	if (exist == 1)
		begin = (start->size->s_maj_min * 2) + 1;
	if (start->optl[0] == 'c' || start->optl[0] == 'b')
		get_maj_min(optl, start, i);
	else
	{
		while (j++ < begin)
			(*optl)[(*i)++] = ' ';
		j = 0;
		while (size[j])
		{
			(*optl)[(*i)++] = size[j];
			j++;
		}
	}
	free(size);
}
