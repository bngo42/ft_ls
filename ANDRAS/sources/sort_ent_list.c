/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ent_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:07:29 by acottier          #+#    #+#             */
/*   Updated: 2016/05/13 17:44:56 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	void	ft_swap(t_ent *up_pos, t_ent *down_pos)
{
	char	*swp;

	swp = ft_strdup(up_pos->name);
	free(up_pos->name);
	up_pos->name = ft_strdup(down_pos->name);
	free(down_pos->name);
	down_pos->name = ft_strdup(swp);
	free(swp);
}

static	int		ft_walkthrough(t_ent **lst)
{
	t_ent	*cursor;

	cursor = *lst;
	if (cursor->next)
	{
		while (cursor->next)
		{
			if (ft_strcmp(cursor->name, cursor->next->name) > 0)
			{
				ft_swap(cursor, cursor->next);
				return (-1);
			}
			cursor = cursor->next;
		}
	}
	return (0);
}

void			ft_sort_ent_list(t_ent **tmp)
{
	int		check;

	check = -1;
	if (*tmp)
	{
		while (check != 0)
			check = ft_walkthrough(tmp);
	}
}
