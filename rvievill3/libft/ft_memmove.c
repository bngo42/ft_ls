/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:37:40 by rvievill          #+#    #+#             */
/*   Updated: 2016/02/19 13:56:54 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp;
	char		*str_dst;
	char		*str_src;

	i = 0;
	str_dst = (char *)dst;
	str_src = (char *)src;
	tmp = (char *)malloc(sizeof(char) * len);
	if ((dst == NULL && src == NULL) || tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str_src[i];
		i = i + 1;
	}
	i = 0;
	while (len > 0)
	{
		str_dst[i] = tmp[i];
		i = i + 1;
		len--;
	}
	return (dst);
}
