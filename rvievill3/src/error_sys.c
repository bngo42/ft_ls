/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_sys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:25:11 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/17 12:21:36 by rvievill         ###   ########.fr       */
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
