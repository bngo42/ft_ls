/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:57:01 by bngo              #+#    #+#             */
/*   Updated: 2015/12/10 17:45:11 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_start(const char *s)
{
	int i;
	int start;

	i = 0;
	start = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		start++;
		i++;
	}
	return (start);
}

static int			ft_end(const char *s, int len)
{
	int i;
	int end;

	i = len - 1;
	end = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		end++;
	}
	return (end);
}

char				*ft_strtrim(char const *s)
{
	char	*copie;
	int		i;
	int		start;
	int		end;
	int		len;

	i = 0;
	if (s)
	{
		len = ft_strlen((char*)s);
		start = ft_start(s);
		end = ft_end(s, len);
		if (start == len)
			return (ft_strdup(""));
		if (!(copie = (char*)malloc(sizeof(char) * (len - start - end + 1))))
			return (NULL);
		while (i < (len - start - end))
		{
			copie[i] = (char)s[i + start];
			i++;
		}
		copie[i] = '\0';
	}
	return (copie);
}
