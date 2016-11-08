/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 11:45:08 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 15:44:40 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_global_treat(char *options, t_arg *args)
{
	if (!options)
		ft_simple_output(args, options);
	else if (ft_strrchr(options, 'R') != 0)
	{
		ft_file_walkthrough(args, options);
		ft_recursive(options, args, NULL);
	}
	else
	{
		ft_file_walkthrough(args, options);
		ft_non_recursive(options, args);
	}
}
