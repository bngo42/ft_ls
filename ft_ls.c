/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/10/11 19:37:00 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_set_spaces(char **str, int len)
{
	int i;
	int j;
	int	length;
	char *tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(len);
	length = ft_strlen(*str);
	if (length < len)
	{
		while (i < (len - length))
		{
			tmp[i] = ' ';
			i++;
		}
		while (i + j < len && str[j])
		{
			tmp[i + j] = *str[j];
			i++;
		}
		tmp[i + j] = '\0';
		ft_strclr(*str);
		*str = ft_strdup(tmp);
	}
}

void	ft_fill_string(int len[4], t_file **lst)
{
	t_file *tmp;

	tmp = *lst;
	while (*lst)
	{
		ft_set_spaces(&(*lst)->link, len[0]);
		ft_set_spaces(&(*lst)->owner, len[0]);
		ft_set_spaces(&(*lst)->group, len[0]);
		ft_set_spaces(&(*lst)->size, len[0]);
		*lst = (*lst)->next;
	}
	*lst = tmp;
}

void	ft_resize_string(t_file *lst)
{
	int		len[4];
	int		ret[4];
	int		i;
	t_file	*tmp;

	tmp = lst;
	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
	while (lst)
	{
		i = 0;
		ret[0] = ft_strlen(lst->link);
		ret[1] = ft_strlen(lst->owner);
		ret[2] = ft_strlen(lst->group);
		ret[3] = ft_strlen(lst->size);
		while (i++ < 3)
			len[i] = (ret[i] > len[i]) ? ret[i] : len[i];
		lst = lst->next;
	}
	ft_fill_string(len, &lst);
}


void	ft_swap_link(t_file **a, t_file **b)
{
	t_file *tmp;

	tmp = *b;
	printf("swaping %s with %s\n", (*a)->name, (*b)->name);
	(*b)->next = (*a)->next;
	(*b)->prev = (*a)->prev;
	(*a)->next = tmp->next;
	(*a)->prev = tmp->prev;
	printf("result to %s and %s\n", (*b)->name, (*a)->name);
}

void	ft_get_mode(t_file **lst,mode_t file)
{
	(*lst)->mode = ft_strnew(10);
	(*lst)->mode[0] = (S_ISDIR(file)) ? 'd' : '-';
	(*lst)->mode[1] = (file & S_IRUSR) ? 'r' : '-';
	(*lst)->mode[2] = (file & S_IWUSR) ? 'w' : '-';
	(*lst)->mode[3] = (file & S_IXUSR) ? 'x' : '-';
	(*lst)->mode[4] = (file & S_IRGRP) ? 'r' : '-';
	(*lst)->mode[5] = (file & S_IWGRP) ? 'w' : '-';
	(*lst)->mode[6] = (file & S_IXGRP) ? 'x' : '-';
	(*lst)->mode[7] = (file & S_IROTH) ? 'r' : '-';
	(*lst)->mode[8] = (file & S_IWOTH) ? 'w' : '-';
	(*lst)->mode[9] = (file & S_IXOTH) ? 'x' : '-';
	ft_putstr(YEL);
	ft_putstr((*lst)->mode);
	ft_putchar(' ');
}

void	ft_get_link(t_file **lst,nlink_t dir)
{
	(*lst)->link = ft_strdup(ft_itoa(dir));
	ft_putstr((*lst)->link);
	ft_putchar(' ');
}

void	ft_get_date(t_file **lst,time_t date)
{
	char *format;

	ft_putstr(GRN);

	(*lst)->date = ft_strnew(1);
	format = ctime(&date);
	ft_strjoin((*lst)->date, ft_strsub(format, 4,4));
	ft_strjoin((*lst)->date, ft_strsub(format, 9,7));
	ft_putstr((*lst)->date);
	ft_putchar(' ');

}

void	ft_get_owner(t_file **lst,uid_t owner)
{
	struct passwd *pswd;

	pswd = getpwuid(owner);
	(*lst)->owner = pswd->pw_name;
	ft_putstr((*lst)->owner);
	ft_putchar(' ');
}

void	ft_get_group(t_file **lst,gid_t groups)
{
	struct group *grp;

	grp = getgrgid(groups);
	(*lst)->group = grp->gr_name;
	ft_putstr((*lst)->group);
	ft_putchar(' ');
}

void	ft_get_size(t_file **lst,off_t size)
{
	(*lst)->size = ft_itoa(size);
	ft_putstr((*lst)->size);
	ft_putchar(' ');
}

void	ft_show_inf(t_file *lst)
{
	ft_putstr(RED);
	ft_get_mode(&lst, lst->info.st_mode);
	ft_get_link(&lst, lst->info.st_nlink);
	ft_get_owner(&lst, lst->info.st_uid);
	ft_get_group(&lst, lst->info.st_gid);
	ft_get_size(&lst, lst->info.st_size);
	ft_get_date(&lst, lst->info.st_mtime);
	ft_putendl(lst->name);
	ft_putstr(END);
}

void	ft_show_list(t_file *lst, int state)
{
	if (!state)
	{
		while (lst)
		{
			ft_show_inf(lst);
			lst = lst->next;
		}
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		while (lst)
		{
			ft_show_inf(lst);
			lst = lst->prev;
		}
	}
}

void ft_push_elem(t_file **start, t_file *new)
{
	t_file	*tmp;
	t_file	*tmp2;

	if (ft_strcmp((*start)->name, new->name) < 0)
	{
		tmp = *start;
		while (*start && ft_strcmp((*start)->name, new->name) < 0)
		{
			tmp2 = *start;
			*start = (*start)->next;
		}
		new->next = tmp2->next;
		new->prev = tmp2;
		tmp2->next = new;
		*start = tmp;
	}
	else
	{
		new->next = *start;
		*start = new;
	}
}
t_file	*ft_new_elem(char *name)
{
	t_file *new;

	if(!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->name = name;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}


int		ft_combine_param(char **argv, char **result)
{
	char	*flag;
	char	*arg;
	int		i;
	int		j;

	i = 0;
	(*result) = "";
	flag = "lRart";
	arg = ft_strnew(0);
	while (argv[i] && !ft_strstr((*result), "--") && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && !ft_strchr(flag, argv[i][j]))
				return (-1);// Options non supporte
			else if (argv[i][j] == '-' && j > 0 && (argv[i][j - 1] != ' ' &&
						argv[i][j - 1] != '-'))
			{
				return (-1);
			}
			else
			{
				arg[0] = argv[i][j];
				(*result) = ft_strjoin((*result), arg);
			}
			j++;
		}

		ft_strdel(&argv[i]);
		i++;
	}
	return (0);
}

int		ft_check_param(char **argv, int *arg)
{
	char	*result;
	char	*flag;
	int		i;
	int		j;

	if ((ft_combine_param(argv, &result)) == -1)
		return (-1);
	//printf("Combined param: %s\n", result);
	flag = "lRart";
	i = 0;
	while (i < 5)
		arg[i++] = 0;
	i = 0;
	while (result[i++])
	{
		j = 0;
		while (result[i] != '-' && flag[j])
		{
			if (result[i] == flag[j])
				arg[j] = 1;
			j++;
		}
	}
	j = 0;
	return (1);
}

int		ft_list_file(DIR *rep, int *arg)//lRart
{
	struct dirent	*data;
	//struct stat		*buf;
	t_file			*lst;
	t_file			*file;

	if ((data = readdir(rep)) == NULL)
		return (-1);
	while (!arg[2] && data->d_name[0] == '.')
	{
		if ((data = readdir(rep)) == NULL)
			return (-1);
	}
	lst = ft_new_elem(data->d_name);
	stat(data->d_name, &lst->info);
	while ((data = readdir(rep)) != NULL)
	{
		if ((arg[2] && data->d_name[0] == '.') || data->d_name[0] != '.')
		{
			file = ft_new_elem(data->d_name);
			ft_push_elem(&lst, file);
			stat(data->d_name, &lst->info);
		}
	}
	ft_show_list(lst, arg[3]);
	ft_putchar('\n');
	return (0);
}
int		main(int argc, char **argv)
{
	int		*arg;
	char	**value;
	int		i;
	DIR		*rep;

	i = 0;
	value = (char**)malloc(sizeof(char*) * (argc - 1));
	arg = (int*)malloc(sizeof(int) * 5);
	while (i < (argc - 1))
	{
		value[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	if (argc > 1 && !(ft_check_param(value, arg)))
	{
		ft_putendl("invalid param");
		return (1);
	}
	i = 0;
	while (i < (argc - 1))
	{
		if (value[i] != NULL)
		{
			if ((rep = opendir(value[i])))
			{
				ft_putstr(BLU);
				ft_putstr(value[i]);
				ft_putendl(":");
				ft_putstr(END);
				ft_list_file(rep, arg);
			}
			else
			{
				ft_putstr("ls: ");
				ft_putstr(value[i]);
				ft_putendl(": No such file or directory");
			}
		}
		i++;
	}
	return (0);
}	
