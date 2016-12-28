/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:48:01 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/11 13:31:20 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			count;
	unsigned char	a;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	a = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (s[count] == a)
		{
			d[count] = s[count];
			return (dst + count + 1);
		}
		d[count] = s[count];
		count++;
	}
	return (NULL);
}
