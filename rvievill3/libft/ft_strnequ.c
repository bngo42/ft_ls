/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:44:08 by rvievill          #+#    #+#             */
/*   Updated: 2015/12/13 12:08:29 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i = i + 1;
	}
	return (1);
}
