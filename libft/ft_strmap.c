/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:22:41 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:16:32 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	int				count;
	int				j;

	count = 0;
	j = ft_strlen((char *)s);
	new = (char *)malloc((j + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[count])
	{
		new[count] = (*f)(s[count]);
		count++;
	}
	new[count] = '\0';
	return (new);
}
