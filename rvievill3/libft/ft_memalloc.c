/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blabla.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:06:18 by rvievill          #+#    #+#             */
/*   Updated: 2016/04/21 21:55:01 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_error_malloc(void)
{
	ft_putendl_fd("malloc failed", 2);
	exit(1);
}

void		*ft_memalloc(size_t size)
{
	void	*memory;
	int		i;

	i = 0;
	memory = (void *)malloc(size);
	if (memory == NULL)
		ft_error_malloc();
	ft_bzero(memory, size);
	return (memory);
}
