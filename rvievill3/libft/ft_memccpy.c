/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:54:53 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/10 16:28:08 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_src;
	unsigned char	*str_dst;

	i = 0;
	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i = i + 1;
	}
	return (NULL);
}
