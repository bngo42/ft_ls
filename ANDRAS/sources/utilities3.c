/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:55:09 by acottier          #+#    #+#             */
/*   Updated: 2016/06/27 11:52:14 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static	char	*get_path(char *str)
{
	while (*str)
		str++;
	while (*str != '/')
		str--;
	str++;
	return (str);
}

void			ft_denied(char *path, int error)
{
	errno = error;
	ft_putstr_err("ft_ls : ");
	ft_putstr_err(get_path(path));
	ft_putstr_err(": ");
	perror("");
}

t_arg			*ft_nano(t_arg *a, t_arg *b)
{
	if (a->info.st_mtimespec.tv_nsec > b->info.st_mtimespec.tv_nsec)
		return (b);
	else
		return (a);
}

t_arg			*ft_endlist(t_arg *lst)
{
	t_arg	*cursor;

	cursor = lst;
	while (cursor->next)
		cursor = cursor->next;
	return (cursor);
}

int				ft_opt_hidden(char *opts)
{
	if (ft_strrchr(opts, 'a') != 0)
		return (1);
	if (ft_strrchr(opts, 'f') != 0)
		return (1);
	return (0);
}
