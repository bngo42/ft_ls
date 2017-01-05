/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:30:31 by bngo              #+#    #+#             */
/*   Updated: 2015/12/07 15:59:37 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	size_t	len;
	char	*s1;
	char	*s2;

	i = 0;
	len = 0;
	s1 = (char*)str1;
	s2 = (char*)str2;
	len = ft_strlen(s2);
	while (i < n && i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
