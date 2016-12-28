/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:26:02 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/04 14:26:46 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*z;
	size_t			count;

	count = 0;
	z = (unsigned char *)s;
	while (count < n)
	{
		if (z[count] == (unsigned char)c)
			return (&z[count]);
		count++;
	}
	return (NULL);
}
