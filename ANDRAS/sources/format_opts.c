/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_opts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:16:45 by acottier          #+#    #+#             */
/*   Updated: 2016/06/21 10:45:22 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*fill_trim(char *tmp, char *trimmed)
{
	while (*tmp)
	{
		if (*tmp == 'l')
			trimmed[1] = 'l';
		else if (*tmp == 'R')
			trimmed[2] = 'R';
		else if (*tmp == 'a')
			trimmed[3] = 'a';
		else if (*tmp == 'r')
			trimmed[4] = 'r';
		else if (*tmp == 't')
			trimmed[5] = 't';
		else if (*tmp == 'f')
			trimmed[6] = 'f';
		else if (*tmp == 'g')
			trimmed[7] = 'g';
		else if (*tmp == 'i')
			trimmed[8] = 'i';
		else if (*tmp == 'o')
			trimmed[9] = 'o';
		else if (*tmp == 'G')
			trimmed[10] = 'G';
		tmp++;
	}
	return (trimmed);
}

static char	*ft_trim(char *tmp)
{
	char	*trimmed;

	trimmed = ft_strnew(11);
	ft_memset(trimmed, '0', 11);
	trimmed[0] = '-';
	return (fill_trim(tmp, trimmed));
}

static int	ft_walkthrough(char *origin, int tosearch)
{
	int		i;

	i = 0;
	while (i < tosearch)
	{
		if (origin[i] == origin[tosearch])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_opts(char *origin)
{
	int		opts;
	int		i;

	i = 0;
	opts = 0;
	while (opts < 6 && origin[i])
	{
		if (origin[i] != '-' && ft_walkthrough(origin, i) == 0)
			opts++;
		if (opts == 6)
			return (opts);
		i++;
	}
	return (opts);
}

char		*ft_format_opts(char *origin)
{
	int		opts;
	char	*tmp;
	int		i;
	int		j;
	char	*res;

	j = -1;
	if (!origin)
		return (NULL);
	opts = ft_count_opts(origin);
	if (opts == -1)
		return (NULL);
	tmp = ft_strnew(opts + 1);
	i = 0;
	while (origin[++j])
	{
		if (ft_isalpha(origin[j]) != 0)
			tmp[i++] = origin[j];
	}
	tmp[i] = '\0';
	res = ft_strrmv(ft_trim(tmp), '0');
	free(tmp);
	free(origin);
	return (res);
}
