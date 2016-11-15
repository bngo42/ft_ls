/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:10:12 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/12 19:58:42 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*res;
	int		i;
	int		size_s1;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = (int)ft_strlen(s1);
	length = size_s1 + ft_strlen(s2);
	if (!(res = ft_strnew(length)))
		return (0);
	while (i < length)
	{
		if (i < size_s1)
			res[i] = (char)s1[i];
		else
			res[i] = (char)s2[i - size_s1];
		i++;
	}
	res[length] = '\0';
	return (res);
}
