/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 20:14:37 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/13 18:45:33 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			error(const char *s, char c)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i = i + 1;
	}
	return (0);
}

static size_t		nb_word(const char *s, char c)
{
	size_t			i;
	size_t			word;

	i = 0;
	word = 0;
	if (s == NULL || c == 0)
		return (0);
	if (error(s, c) == 0 && s[0] != '\0')
		return (1);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word = word + 1;
		i = i + 1;
	}
	return (word);
}

static void			filling(char **str, const char *s, char c)
{
	size_t			j;
	size_t			k;
	size_t			i;

	i = 0;
	k = 0;
	j = 0;
	if (str != NULL || s != NULL || c != 0)
	{
		while (s[j])
		{
			if (s[j] != c)
				str[i][k++] = s[j];
			if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0'))
			{
				str[i++][k] = '\0';
				k = 0;
			}
			j = j + 1;
		}
		if (i == 0 && nb_word(s, c) != 0)
			i++;
		str[i] = 0;
	}
}

char				**ft_strsplit(const char *s, char c)
{
	char			**str;
	size_t			i;

	i = 0;
	if (s == NULL || c == 0)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * nb_word(s, c) + 1);
	if (str == NULL)
		return (NULL);
	while (i < nb_word(s, c))
	{
		str[i] = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		i = i + 1;
	}
	filling(str, s, c);
	return (str);
}
