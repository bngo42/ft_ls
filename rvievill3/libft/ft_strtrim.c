/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 07:00:02 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/13 18:46:07 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	last_index(char const *s)
{
	size_t		i;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) == 0)
	{
		i = 0;
		return (i);
	}
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i != 0)
		i = i - 1;
	return (i);
}

static int		size(char const *s)
{
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s[j] == '\0')
		return (0);
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j != 0)
		j = j - 1;
	j++;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i = i + 1;
	if (j - i < 0)
		return (0);
	return (j - i);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	k = 0;
	j = last_index(s);
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i = i + 1;
	str = (char *)malloc(sizeof(char) * size(s) + 1);
	if (str == NULL)
		return (NULL);
	while (i <= j)
	{
		str[k] = s[i];
		i = i + 1;
		k = k + 1;
	}
	str[k] = '\0';
	return (str);
}
