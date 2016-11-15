/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 15:35:08 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 20:50:41 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int				size_lst(t_lst *start, char *opt)
{
	int			i;

	i = 0;
	if (ft_strchr(opt, 'a') == NULL)
	{
		while (start && start->file != NULL)
		{
			if (start->file[0] != '.')
				i++;
			start = start->next;
		}
	}
	else
	{
		while (start && start->file != NULL)
		{
			i++;
			start = start->next;
		}
	}
	return (i);
}

static int		hide_file(t_lst *start)
{
	while (start)
	{
		if (!ft_strcmp(start->file, ".") || !ft_strcmp(start->file, ".."))
			return (1);
		start = start->next;
	}
	return (0);
}

static void		display_total(t_lst *start, char *opt)
{
	int			res;
	t_lst		*begin;
	int			size;
	int			enter;

	enter = hide_file(start);
	res = 0;
	size = size_lst(start, opt);
	begin = start;
	while (begin)
	{
		if (ft_strchr(opt, 'a'))
			res = res + begin->stat.st_blocks;
		else if (begin->file[0] != '.')
			res = res + begin->stat.st_blocks;
		begin = begin->next;
	}
	if (enter == 1 && size > 0)
	{
		ft_putstr("total ");
		ft_putnbr(res);
		ft_putchar('\n');
	}
}

void			display(char *arg, t_lst *start, int exist)
{
	if (ft_strchr(arg, 'l'))
		display_total(start, arg);
	while (start)
	{
		if (ft_strchr(arg, 'l') == NULL)
		{
			if (ft_strchr(arg, 'f') == NULL && ft_strchr(arg, 'a') == NULL
					&& start->file[0] == '.')
				start = start->next;
			else
			{
				print_color(start, arg);
				start = start->next;
			}
		}
		else
			display_l(&start, arg, exist);
	}
	free_lst(start);
}

void			display_first_dir(char *start, int size, char **file)
{
	if (size > 1 || file != NULL)
	{
		ft_putstr(start);
		ft_putstr(":\n");
	}
}
