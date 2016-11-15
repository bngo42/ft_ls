/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:15:01 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:15:02 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			display_l(t_lst **start, char *arg, int exist)
{
	if (ft_strchr(arg, 'a') == NULL && (*start)->file[0] == '.'
			&& ft_strchr((*start)->file, '/') == NULL)
		*start = (*start)->next;
	else
	{
		filling_optl(*start, exist);
		ft_putstr((*start)->optl);
		if ((*start)->optl[0] == 'l')
		{
			print_color(*start, arg);
			ft_putstr(" -> ");
			ft_putendl((*start)->link);
		}
		else
			print_color(*start, arg);
		*start = (*start)->next;
	}
}
