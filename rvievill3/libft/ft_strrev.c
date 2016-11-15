/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:15:27 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/12 18:15:14 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] != '\0')
	{
		if (i < j)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
		}
		i = i + 1;
		j = j - 1;
	}
	return (str);
}
