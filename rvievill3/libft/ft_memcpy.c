/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:01:24 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/04 17:27:47 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str_src;
	unsigned char	*str_dst;

	i = 0;
	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	if ((dst == NULL && src == NULL))
		return (NULL);
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i = i + 1;
	}
	return (dst);
}
