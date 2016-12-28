/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:30:20 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 10:02:30 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int		get_size(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		ft_sign(int a)
{
	if (a < 0)
		return (1);
	return (0);
}

static int		calcul(int b)
{
	if (b < 0)
		return (-b);
	return (b);
}

char			*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		sign;

	sign = ft_sign(n);
	i = get_size(n);
	p = NULL;
	p = (char *)malloc(sizeof(char) * (sign + i + 1));
	if (p)
	{
		p = p + i + sign;
		*p = '\0';
		if (!n)
			*--p = '0';
		while (n != 0)
		{
			*--p = calcul(n % 10) + '0';
			n = n / 10;
		}
		if (sign)
			*--p = '-';
	}
	return (p);
}
