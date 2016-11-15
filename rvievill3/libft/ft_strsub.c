/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 03:01:11 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/16 18:03:02 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL || s == NULL)
		return (NULL);
	while (i != len)
	{
		str[i] = s[start];
		i = i + 1;
		start = start + 1;
	}
	str[i] = '\0';
	return (str);
}
