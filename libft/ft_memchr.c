/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:56:23 by bngo              #+#    #+#             */
/*   Updated: 2015/12/02 13:47:01 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;

	i = 0;
	str = (char*)s;
	while (i < n)
	{
		if (str[i] == (char)c)
			return (char *)&s[i];
		i++;
	}
	return (NULL);
}
