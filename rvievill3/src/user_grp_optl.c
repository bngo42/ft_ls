/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_grp_optl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:16:07 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:16:14 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void				user(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*usr;
	int				j;

	j = 0;
	usr = ft_strdup(getpwuid(start->stat.st_uid)->pw_name);
	begin = (start->size->s_user - 1);
	while (usr[j])
	{
		(*optl)[*i] = usr[j];
		j++;
		(*i)++;
	}
	while (j < begin)
	{
		(*optl)[*i] = ' ';
		j++;
		(*i)++;
	}
	free(usr);
}

void				grp(char **optl, t_lst *start, int *i)
{
	int				begin;
	char			*grp;
	int				j;

	j = 0;
	grp = ft_strdup(getgrgid(start->stat.st_gid)->gr_name);
	begin = (start->size->s_grp - 1);
	while (grp[j])
	{
		(*optl)[*i] = grp[j];
		j++;
		(*i)++;
	}
	while (j < begin)
	{
		(*optl)[*i] = ' ';
		j++;
		(*i)++;
	}
	free(grp);
}
