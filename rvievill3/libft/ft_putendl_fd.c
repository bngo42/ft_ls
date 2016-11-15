/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:37:31 by rvievill          #+#    #+#             */
/*   Updated: 2015/11/29 15:25:28 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl_fd(char const *s, int fd)
{
	size_t		i;

	i = 0;
	if (s != NULL && fd != -1)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i = i + 1;
		}
		ft_putchar_fd('\n', fd);
	}
}
