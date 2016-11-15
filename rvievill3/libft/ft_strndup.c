/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:26:57 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/12 18:27:48 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strndup(const char *s1, int n)
{
	char		*tab;
	size_t		i;

	tab = (char *)malloc(sizeof(char) * n + 1);
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (s1[i] && n != 0)
	{
		tab[i] = s1[i];
		i = i + 1;
		n = n - 1;
	}
	tab[i] = '\0';
	return (tab);
}
