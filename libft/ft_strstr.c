/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 20:26:09 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 09:59:01 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *c1;
	const char *c2;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		c1 = s1;
		c2 = s2;
		while (*c2 != '\0' && *c1 == *c2)
		{
			c1++;
			c2++;
		}
		if (*c2 == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
