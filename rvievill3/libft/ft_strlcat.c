/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 01:56:07 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/13 12:06:17 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t		i;
	size_t		save;
	size_t		j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	save = i;
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size != save)
		dst[i] = '\0';
	return (save + ft_strlen(src));
}
