/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:48:14 by bngo              #+#    #+#             */
/*   Updated: 2015/12/10 17:21:45 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*stmp;
	char	*dtmp;

	dtmp = (char *)dst;
	stmp = (char *)src;
	if (stmp < dtmp)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dtmp[i] = stmp[i];
			i--;
		}
	}
	else if (stmp != dtmp)
	{
		i = -1;
		while (++i < (int)len)
			dtmp[i] = stmp[i];
	}
	return (dst);
}
