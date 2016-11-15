/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:14:54 by bngo              #+#    #+#             */
/*   Updated: 2016/11/15 20:14:55 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int					b_or_c(t_lst *start)
{
	while (start)
	{
		if (S_ISCHR(start->stat.st_mode) || S_ISBLK(start->stat.st_mode))
			return (1);
		start = start->next;
	}
	return (0);
}

static void			display_file(char *opt, char **dir, char **file, int path)
{
	display(opt, lst(file, opt), b_or_c(lst(file, opt)));
	if (dir[0] != NULL && ft_strcmp(dir[0], ".") != 0)
	{
		ft_putstr("\n");
		riffle_path(opt, dir, file, path);
	}
}

static void			lst_path(char *opt, char **str, int path)
{
	char			**file;
	char			**dir;

	dir = (ft_strchr(opt, 'l') ? stock_dir_l(str, opt) : stock_dir(str, opt));
	file = (ft_strchr(opt, 'l') ? stock_file_l(str) : stock_file(str));
	if ((dir_error(str, opt)) == 1)
		return ;
	if (file != NULL)
	{
		display_file(opt, dir, file, path);
	}
	else if (dir != NULL)
		riffle_path(opt, dir, file, path);
	if (file)
		free_tab(file);
}

int					main(int ac, char **av)
{
	int				i;
	char			**str;
	char			*opt;
	int				path;

	i = 0;
	str = ft_cpyav(av);
	if (bad_option(str) == 1)
		return (1);
	while (str[i] && str[i][0] == '-' && str[i][1] != '-' && str[i][1] != '\0')
		i++;
	if (str[i] && str[i][0] == '-' && str[i][1] == '-')
		i++;
	opt = option_in_arg(str);
	if ((path = (ac - 1) - i) != 0)
		lst_path(opt, str, path);
	else
	{
		str[0] = ft_strdup(".");
		str[1] = 0;
		riffle_path(opt, str, stock_file(str), path);
	}
	free(opt);
	free_tab(str);
	return (0);
}
