/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_opts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:40:54 by acottier          #+#    #+#             */
/*   Updated: 2016/06/21 10:33:58 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_check_opts(char *input)
{
	char	cache;

	while (input)
	{
		if (*input != 'l' && *input != 'R' && *input != 'a' && *input != '-'
			&& *input != 'a' && *input != 'r' && *input != 't'
			&& *input != 'f' && *input != 'g' && *input != 'i'
			&& *input != 'o' && *input != 'G')
			return (*input);
		if (cache && *input == '-' && cache == '-')
			return (*input);
		cache = *input;
		input++;
	}
	return (0);
}
