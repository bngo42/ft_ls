/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:37:34 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/03 15:48:02 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				a;
	char			b;
	char			*d;

	a = 0;
	b = (char)c;
	d = (char *)s;
	while (d[a])
		a++;
	while (a >= 0)
	{
		if (d[a] == b)
			return (&d[a]);
		a--;
	}
	return (0);
}
