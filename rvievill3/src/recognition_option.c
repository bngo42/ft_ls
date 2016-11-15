/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:15:15 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:15:16 by bngo             ###   ########.fr       */
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
