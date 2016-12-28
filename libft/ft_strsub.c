/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:57:08 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:00:21 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *p;

	if (s || !len)
	{
		p = ft_strnew(len);
		if (p)
			ft_strncpy(p, &s[start], len);
		return (p);
	}
	return (NULL);
}
