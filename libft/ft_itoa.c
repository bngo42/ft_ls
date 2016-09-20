/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:07:09 by bngo              #+#    #+#             */
/*   Updated: 2015/12/23 12:24:38 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_writenbr(int n, int bol, int i, char *res)
{
	int k;

	k = n;
	res[i] = '\0';
	if (bol == 1)
		res[0] = '-';
	while ((--i >= 0 && bol == 0) || (i > 0 && bol == 1))
	{
		res[i] = (k % 10) + 48;
		k = (k - (k % 10)) / 10;
	}
	return (res);
}

static int		ft_length(int i, int n)
{
	int k;

	k = n;
	while (k != 0)
	{
		k = (k - (k % 10)) / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	int		boul;
	char	*res;

	i = 0;
	boul = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		boul = 1;
		n = -n;
		i++;
	}
	i = ft_length(i, n);
	if (n == 0)
	{
		if (!(res = (char*)malloc(sizeof(char) * 2)))
			return (0);
		return (ft_strdup("0"));
	}
	if ((res = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	return (ft_writenbr(n, boul, i, res));
}
