/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 20:08:42 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/18 19:45:55 by rvievill         ###   ########.fr       */
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
