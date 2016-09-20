/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/09/20 16:46:17 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR *rep;
	struct dirent *data;
	
	rep = NULL;

	if (argc > 0)
	{
		if(!(rep = opendir(argv[1])))
			return (-1);
		while ((data = readdir(rep)) != NULL)
		{
			ft_putstr(data->d_name);
			ft_putchar('\t');
		}
	}
	return (0);
}
