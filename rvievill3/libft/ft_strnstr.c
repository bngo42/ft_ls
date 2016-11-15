/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:35:51 by rvievill          #+#    #+#             */
/*   Updated: 2015/11/29 15:39:12 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	str = (char *)s1;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] != '\0' && i + j < n)
			j = j + 1;
		if (s2[j] == '\0')
			return (&str[i]);
		i = i + 1;
	}
	return (0);
}
