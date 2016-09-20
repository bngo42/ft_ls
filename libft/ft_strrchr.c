/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:37:54 by bngo              #+#    #+#             */
/*   Updated: 2015/12/02 11:36:33 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] == (char)c)
		return (char*)&s[i];
	return (NULL);
}
