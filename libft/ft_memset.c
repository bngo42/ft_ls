/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:39:52 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/02 14:57:35 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*var;
	size_t			count;

	count = 0;
	var = (unsigned char *)b;
	while (count < len)
	{
		var[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
