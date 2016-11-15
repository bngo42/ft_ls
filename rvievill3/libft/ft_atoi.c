/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:02:39 by rvievill          #+#    #+#             */
/*   Updated: 2016/02/19 14:02:05 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	size_t		i;
	size_t		begin;
	int			nb;

	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i = i + 1;
	begin = i;
	if (str[i] == '-' || str[i] == '+')
		i = i + 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i = i + 1;
	}
	if (str[begin] == '-')
		return (-nb);
	return (nb);
}
