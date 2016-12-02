/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:06:24 by lvalenti          #+#    #+#             */
/*   Updated: 2016/12/02 11:49:54 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void		aff_stat(t_rep *data)
{
	printf("ko\n");
	printf("testing filestat\n");
	if (data != NULL)
	{
		printf("filestat != NULL\n");
		// printf("%u\n", data->filestat->st_uid);
	}
	else
		printf("filestat == NULL\n");
	printf("ko2\n");
	// struct group *gid;

	// printf("ok\n");
	// data->mode = data->filestat->st_mode;
}
