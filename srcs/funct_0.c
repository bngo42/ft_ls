/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:46:39 by bngo              #+#    #+#             */
/*   Updated: 2017/01/05 11:46:44 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		funct_t(t_rep *lst)
{
	t_rep			*tmp;

	tmp = NULL;
	tmp = lst;
	while (tmp)
	{
		errno = 0;
		if (lstat(tmp->name2, &tmp->filestat) < 0)
		{
			perror("ls ");
			return ;
		}
		tmp->time_s = tmp->filestat.st_mtimespec.tv_sec;
		tmp->time_ns = tmp->filestat.st_mtimespec.tv_nsec;
		tmp = tmp->next;
	}
	tmp = lst;
	funct_t_2(tmp, lst);
}

void		funct_t_2(t_rep *tmp, t_rep *lst)
{
	while (tmp && tmp->next)
	{
		if (tmp->time_s < tmp->next->time_s)
		{
			swap_link(tmp);
			tmp = lst;
		}
		else if (tmp->time_s == tmp->next->time_s)
		{
			if (tmp->time_ns < tmp->next->time_ns)
			{
				swap_link(tmp);
				tmp = lst;
			}
		}
		tmp = tmp->next;
	}
}

void		funct_gr(t_rep *lst, t_opt *opt)
{
	t_rep	*tmp;

	tmp = lst;
	while (tmp)
	{
		errno = 0;
		if (lstat(tmp->name2, &tmp->filestat) < 0)
		{
			perror("ls ");
			return ;
		}
		if (S_ISDIR(tmp->filestat.st_mode))
			funct_gr_2(tmp, opt);
		tmp = tmp->next;
	}
}

void		funct_gr_2(t_rep *tmp, t_opt *opt)
{
	if (opt->a == 0)
	{
		if (tmp->name[0] != '.')
			read_arg(tmp->name2, opt);
	}
	else if (opt->a == 1)
	{
		if (tmp->name[0] != '.')
			read_arg(tmp->name2, opt);
		if ((tmp->name[0] == '.' && tmp->name[1] != '.') &&
				(tmp->name[0] == '.' && tmp->name[1] != '\0'))
			read_arg(tmp->name2, opt);
	}
}

t_rep		*funct_pr(t_rep *r)
{
	if (r->prev)
	{
		reverse_link(r);
		r = r->prev;
	}
	while (r)
	{
		reverse_link(r);
		if (r->prev == NULL)
			return (r);
		r = r->prev;
	}
	return (r);
}
