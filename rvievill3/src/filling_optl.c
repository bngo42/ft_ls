/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_optl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:13:00 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:13:01 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			nb_space(char **optl, int *i, int nb)
{
	int				size;

	size = *i + nb;
	while (*i < size)
	{
		(*optl)[*i] = ' ';
		(*i)++;
	}
}

void				filling_optl(t_lst *start, int exist)
{
	int				i;

	i = 0;
	start->optl = (char *)malloc(sizeof(char) * start->size->all);
	access_file(&(start->optl), start, &i);
	nb_space(&(start->optl), &i, 2);
	lnk(&(start->optl), start, &i);
	nb_space(&(start->optl), &i, 1);
	user(&(start->optl), start, &i);
	nb_space(&(start->optl), &i, 2);
	grp(&(start->optl), start, &i);
	nb_space(&(start->optl), &i, 2);
	size(&(start->optl), start, &i, exist);
	nb_space(&(start->optl), &i, 1);
	time_optl(&(start->optl), start, &i);
	nb_space(&(start->optl), &i, 1);
	while (start->optl[i])
	{
		start->optl[i] = '\0';
		i++;
	}
}
