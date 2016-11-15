/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:25:20 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 15:59:02 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			first_size(t_lst *cur)
{
	cur->size = (t_optl *)malloc(sizeof(t_optl));
	cur->size->s_acces = 0;
	cur->size->s_lnk = 0;
	cur->size->s_user = 0;
	cur->size->s_grp = 0;
	cur->size->s_size = 0;
	cur->size->s_time = 0;
	cur->size->s_name = 0;
	cur->size->s_total = 0;
	cur->size->s_maj_min = 0;
	cur->size->all = 0;
}

void			filling_size(t_lst *cur)
{
	char		*itoa_lnk;
	char		*itoa_size;
	char		*minor;
	char		*major;

	minor = ft_itoa(cur->minor);
	major = ft_itoa(cur->major);
	itoa_lnk = ft_itoa(cur->stat.st_nlink);
	itoa_size = ft_itoa(cur->stat.st_size);
	cur->size->s_lnk = ft_strlen(itoa_lnk);
	free(itoa_lnk);
	cur->size->s_maj_min = (ft_strlen(major) < ft_strlen(minor))
		? ft_strlen(minor) : ft_strlen(major);
	cur->size->s_total = cur->stat.st_blocks;
	cur->size->s_user = ft_strlen(getpwuid(cur->stat.st_uid)->pw_name) + 1;
	cur->size->s_grp = ft_strlen(getgrgid(cur->stat.st_gid)->gr_name) + 1;
	cur->size->s_size = ft_strlen(itoa_size);
	free(itoa_size);
	cur->size->s_name = ft_strlen(cur->file);
	cur->size->all = 12 + 13 + cur->size->s_lnk + cur->size->s_user
		+ cur->size->s_grp + cur->size->s_size + cur->size->s_name
		+ cur->size->s_maj_min;
}

void			cmp_optl(t_lst *start, t_lst *new, char *opt)
{
	char		*res;

	res = ft_strchr(opt, 'a');
	first_size(new);
	filling_size(new);
	if (start->size->s_maj_min < new->size->s_maj_min)
		start->size->s_maj_min = new->size->s_maj_min;
	if (res == NULL)
	{
		if (start->size->s_lnk < new->size->s_lnk && new->file[0] != '.')
			start->size->s_lnk = new->size->s_lnk;
	}
	else if (start->size->s_lnk < new->size->s_lnk)
		start->size->s_lnk = new->size->s_lnk;
	if (start->size->s_size < new->size->s_size)
		start->size->s_size = new->size->s_size;
	if (start->size->s_user < new->size->s_user)
		start->size->s_user = new->size->s_user;
	if (start->size->s_grp < new->size->s_grp)
		start->size->s_grp = new->size->s_grp;
	if (start->size->all < new->size->all)
		start->size->all = new->size->all;
	new->size = start->size;
}
