/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:15:58 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/17 18:24:02 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_cpyav(char **av)
{
	char		**str;
	int			i;
	int			size;

	i = 1;
	size = 0;
	while (av[i])
	{
		size++;
		i++;
	}
	str = (char **)malloc(sizeof(char *) * size + 1);
	i = 0;
	while (i < size)
	{
		str[i] = ft_strdup(av[i + 1]);
		i++;
	}
	str[i] = 0;
	return (str);
}
