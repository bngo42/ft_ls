/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:48:28 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 20:50:42 by rvievill         ###   ########.fr       */
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
