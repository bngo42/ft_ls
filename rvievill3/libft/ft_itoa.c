/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blabla.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:05:20 by rvievill          #+#    #+#             */
/*   Updated: 2016/05/27 16:28:20 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void		alocation(int n, int *div, int *size)
{
	*size = 2;
	*div = 1;
	if (n >= 0)
	{
		*size = 1;
		n = -n;
	}
	while (n / *div < -9)
	{
		*div = *div * 10;
		*size = *size + 1;
	}
}

char			*ft_itoa(long int n)
{
	char		*str;
	int			i;
	int			div;
	int			size;

	i = 0;
	alocation(n, &div, &size);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i = i + 1;
	}
	if (n >= 0)
		n = -n;
	while (div >= 1)
	{
		str[i] = -(n / div % 10) + '0';
		i = i + 1;
		div = div / 10;
	}
	str[i] = '\0';
	return (str);
}
