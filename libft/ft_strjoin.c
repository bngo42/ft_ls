/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:04:29 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:01:39 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		count;
	int		size;

	size = (ft_strlen(s1) + ft_strlen(s2));
	count = 0;
	mem = (char *)malloc(sizeof(char*) * size);
	if (!mem)
		return (NULL);
	while (s1[count])
	{
		mem[count] = s1[count];
		count++;
	}
	while (*s2)
	{
		mem[count] = *s2;
		count++;
		++s2;
	}
	mem[count] = '\0';
	return (mem);
}
