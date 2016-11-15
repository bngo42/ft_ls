/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:25:14 by rvievill          #+#    #+#             */
/*   Updated: 2016/04/17 15:08:23 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char			*ft_strdup(const char *s1)
{
	char		*tab;
	size_t		i;

	tab = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i = i + 1;
	}
	tab[i] = '\0';
	return (tab);
}
