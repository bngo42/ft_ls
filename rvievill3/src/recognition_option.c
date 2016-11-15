/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:37:53 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/18 19:50:16 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char				*option_in_arg(char **av)
{
	char			*tab;
	int				i;

	i = 0;
	tab = ft_strnew(0);
	while (av[i] && av[i][0] == '-' && av[i][1] != '-')
	{
		tab = ft_strjoin(tab, av[i]);
		i++;
	}
	return (tab);
}
