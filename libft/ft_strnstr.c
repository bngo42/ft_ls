/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:32:58 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 09:59:23 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t count;
	size_t j;

	count = 0;
	if (!ft_strlen(s2))
		return ((char*)s1);
	while (count < n && s1[count])
	{
		j = 0;
		if (s2[j] == s1[count + j])
		{
			while ((s2[j] == s1[count + j]) && (count + j) < n)
			{
				if (s2[j + 1] == '\0')
					return ((char*)s1 + count);
				j++;
			}
		}
		count++;
	}
	return (NULL);
}
