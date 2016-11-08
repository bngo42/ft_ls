/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_dir_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:47:20 by acottier          #+#    #+#             */
/*   Updated: 2016/05/20 16:27:54 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_show_dir_content(char *path)
{
	DIR				*current;
	struct dirent	*entry;
	struct stat		info;

	lstat(path, &info);
	if (S_ISDIR(info.st_mode) == 0)
		return ;
	errno = 0;
	current = opendir(path);
	if (!current)
	{
		ft_denied(path, errno);
		return ;
	}
	while ((entry = readdir(current)) != NULL)
	{
		if (entry->d_name[0] != '.')
			ft_putendl(entry->d_name);
	}
	closedir(current);
}
