/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:32:46 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:01:54 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*p;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	p = (char *)s + len - 1;
	while (*s && ft_isspace(*s))
	{
		s++;
		len--;
	}
	while (p >= s && ft_isspace(*p))
	{
		p--;
		len--;
	}
	p = ft_strnew(len);
	if (!p)
		return (NULL);
	ft_strncpy(p, s, len);
	return (p);
}
