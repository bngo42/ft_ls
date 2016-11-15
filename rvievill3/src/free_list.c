/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:14:35 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:14:36 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			free_lst(t_lst *start)
{
	t_lst		*tmp;

	tmp = start;
	while (tmp)
	{
		free(start);
		tmp = tmp->next;
		start = tmp;
	}
	if (tmp)
		free(tmp);
}
