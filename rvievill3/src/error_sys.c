/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_sys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:12:30 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:12:32 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

static void			display_error_a(char *elem)
{
	char			*name;

	if ((name = ft_strrchr(elem, '/')))
	{
		ft_putstr_fd("ft_ls: ", 2);
		if (ft_strcmp(name, "/") != 0)
			perror(name + 1);
		else
		{
			ft_putstr_fd(": ", 2);
			perror(NULL);
		}
	}
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(elem);
	}
}

static void			display_error(char *elem)
{
	char			*name;

	if (elem[0] != '.')
	{
		if ((name = ft_strrchr(elem, '/')))
		{
			ft_putstr_fd("ft_ls: ", 2);
			if (ft_strcmp(name, "/") != 0)
				perror(name + 1);
			else
			{
				ft_putstr_fd(": ", 2);
				perror(NULL);
			}
		}
		else
		{
			ft_putstr_fd("ft_ls: ", 2);
			perror(elem);
		}
	}
}

void				permission_denied(char *elem, char *opt)
{
	if (!ft_strchr(opt, 'a'))
		display_error(elem);
	else
		display_error_a(elem);
}
