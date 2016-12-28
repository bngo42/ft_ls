/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:40:41 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/04 14:27:05 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*e;
	size_t			count;

	d = (unsigned char *)s1;
	e = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (d[count] != e[count])
			return (((int)d[count] - (int)e[count]));
		count++;
	}
	return (0);
}
