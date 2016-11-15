/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:59:18 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/07 15:41:46 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	str = (char *)s1;
	if (str[0] == '\0' && s2[0] == '\0')
		return (&str[i]);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] != '\0')
			j = j + 1;
		if (s2[j] == '\0')
			return (&str[i]);
		i = i + 1;
	}
	return (0);
}
