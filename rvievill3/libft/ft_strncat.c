/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:17:07 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/07 16:37:26 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (n == 0)
		return (s1);
	while (s1[i])
		i = i + 1;
	while (s2[j] && n > 0)
	{
		s1[i + j] = s2[j];
		j = j + 1;
		n = n - 1;
	}
	s1[i + j] = '\0';
	return (s1);
}
