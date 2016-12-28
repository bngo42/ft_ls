/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:10:00 by lvalenti          #+#    #+#             */
/*   Updated: 2015/12/03 14:01:20 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	if (!n)
		return (0);
	while (s1[a] && s2[a] && s1[a] == s2[a] && a + 1 < n)
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
