/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:25:51 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/03 15:23:37 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				a;
	unsigned char	b;
	char			*d;

	a = 0;
	b = (unsigned char)c;
	d = (char *)s;
	while (d[a] != b && d[a])
		a++;
	if (d[a] == b)
		return (&d[a]);
	return (NULL);
}
