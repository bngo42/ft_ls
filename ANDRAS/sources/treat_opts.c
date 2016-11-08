/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_opts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:25:05 by acottier          #+#    #+#             */
/*   Updated: 2016/06/20 14:59:43 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	int		ft_check(char **argv, int i)
{
	if (!argv[i] || argv[i][0] != '-')
		return (0);
	if (argv[i][1] == '-' && !argv[i][2])
		return (0);
	return (1);
}

static	char	*ft_compact(char **argv, int *i)
{
	char	*tmp;
	char	*compacted;

	compacted = NULL;
	while (ft_check(argv, *i))
	{
		if (ft_strlen(argv[*i]) < 2)
			return (0);
		tmp = ft_strjoin(compacted, argv[*i]);
		if (compacted)
			free(compacted);
		compacted = ft_strdup(tmp);
		free(tmp);
		(*i)++;
	}
	return (compacted);
}

char			*ft_treat_opts(char **argv, int *err, char *errchar)
{
	char	*compacted;
	int		i;

	i = 1;
	if (!argv[1] || argv[1][0] != '-')
		return (NULL);
	compacted = ft_compact(argv, &i);
	*errchar = ft_check_opts(compacted);
	if (*errchar != 0)
		*err = 2;
	compacted = ft_format_opts(compacted);
	return (compacted);
}
