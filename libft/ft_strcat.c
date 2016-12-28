/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:16:52 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/02 16:32:31 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (dst[i])
		i++;
	while (src[d])
	{
		dst[i] = src[d];
		i++;
		d++;
	}
	dst[i] = '\0';
	return (dst);
}
