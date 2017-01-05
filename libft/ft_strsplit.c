/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 14:41:04 by bngo              #+#    #+#             */
/*   Updated: 2015/12/10 17:57:24 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		count_words(char *s, char c)
{
	int words;

	while (*s && *s == c)
		++s;
	words = (*s) ? 1 : 0;
	while (*s)
	{
		if (*s == c && s[1] && s[1] != c)
			++words;
		++s;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	char	*start;
	char	**result;

	if (!s || !c)
		return (NULL);
	words = count_words((char*)s, c);
	result = (char**)malloc(sizeof(char*) * (count_words((char*)s, c) + 1));
	if (result == NULL)
		return (NULL);
	start = (char*)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(result++) = ft_strsub(start, 0, s - start);
			start = (char*)s + 1;
		}
		++s;
	}
	if (start != s)
		*(result++) = ft_strsub(start, 0, s - start);
	*result = NULL;
	return (result - words);
}
