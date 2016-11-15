/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_optl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:01:22 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/20 17:14:35 by rvievill         ###   ########.fr       */
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
