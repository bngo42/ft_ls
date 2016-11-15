/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blabla.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:04:20 by rvievill          #+#    #+#             */
/*   Updated: 2016/02/02 11:02:54 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	str[size] = '\0';
	while (str[i])
	{
		str[i] = '\0';
		i = i + 1;
	}
	return (str);
}
