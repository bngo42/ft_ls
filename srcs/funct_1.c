/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:41:44 by bngo              #+#    #+#             */
/*   Updated: 2017/01/05 11:42:57 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		funct_l(t_rep *r, t_opt *opt)
{
	t_rep	*tmp;
	t_rep	*lst;

	tmp = r;
	if (!(lst = (t_rep *)ft_memalloc(sizeof(t_rep))))
		return ;
	while (tmp)
	{
		funct_l_2(tmp, opt);
		tmp = tmp->next;
	}
	if (r->type == 0)
	{
		ft_putstr("total ");
		ft_putnbr(opt->len[6]);
		ft_putchar('\n');
	}
	free_lst(lst);
}

void		funct_l_2(t_rep *tmp, t_opt *opt)
{
	errno = 0;
	if (lstat(tmp->name2, &tmp->filestat) < 0)
	{
		perror("ls");
		return ;
	}
	if (opt->a == 0)
	{
		if (tmp->name[0] != '.')
			get_len(tmp, opt);
	}
	else if (opt->a == 1)
		get_len(tmp, opt);
}
