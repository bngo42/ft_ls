/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:30:51 by lvalenti          #+#    #+#             */
/*   Updated: 2016/02/19 09:59:44 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int		ft_atoi(char const *str)
{
	int		i;
	long	sum;
	char	sign;

	sum = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = 0;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
		sum = sum * 10 + (str[i++] - '0');
	if (sign)
		return (sum);
	else
		return (-sum);
}
