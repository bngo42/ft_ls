/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:38:19 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 09:58:31 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t y;

	y = 0;
	i = ft_strlen(dst);
	while (n > 0)
	{
		dst[i] = src[y];
		i++;
		y++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}
