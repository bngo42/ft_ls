/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:21:35 by bngo              #+#    #+#             */
/*   Updated: 2015/12/10 17:32:57 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (s1[i] != '\0')
			str[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			str[j++] = s2[i++];
		str[j] = '\0';
	}
	return (str);
}
