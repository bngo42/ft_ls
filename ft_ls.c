/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/09/27 18:00:52 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	ft_show_list(t_file *lst)
{
	t_file	*tmp;

	tmp = lst;
	while (lst)
	{
		ft_putstr(RED);
		ft_putendl(lst->name);
		ft_putstr(END);
		lst = lst->next;
	}
	lst = tmp;
}

void	ft_add_elem(t_file **lst, t_file **elem, char *name)
{
	t_file *tmp;

	tmp = *lst;
	while ((*lst)->next && !ft_strequ(name, (*lst)->name))
		*lst = (*lst)->next;
	if (ft_strequ(name, (*lst)->name))
	{
		(*elem)->next = (*lst)->next;
		(*elem)->prev = (*lst);
		(*lst)->next = (*elem);
	}
	*lst = tmp;
}

void	ft_sort_lst(t_file **lst)
{
	int		i;
	int		len;
	t_file	*tmp;

	tmp = *lst;
	i = 0;
	len = 0;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		len++;
	}
	*lst = tmp;
	while (i < (len - 1))
	{
		if (ft_strcmp((*lst)->name, (*lst)->next->name) < 0)
			ft_swap_link(&(*lst), &(*lst)->next);
		*lst = (*lst)->next;
		i++;
	}
}
/*
   void	ft_push_back(t_file **lst, t_file *elem)
   {
   t_file *tmp;

   tmp = *lst;
//printf("start = %s\n", (*lst)->name);
//printf("elem = %s\n\n", (*elem)->name);
printf("--------------START--------------------\n");
ft_show_list(*lst);
printf("---------------END-----------------\n");
printf("#####################################\n");
if (ft_strcmp(elem->name, (*lst)->name) < 0)
{
elem->next = *lst;
(*lst)->prev = elem;
 *lst = elem;
 }
 else
 {
 while ((*lst)->next && ft_strcmp(elem->name, (*lst)->name) > 0)
 {
 *lst = (*lst)->next;
 }
//	printf("cur lst = %s\n", (*lst)->name);
//	printf("fdp = %s\n", (*elem)->name);
elem->next = (*lst)->next;
(*lst)->next = elem;
elem->prev = (*lst);
 *lst = tmp;
 }
 }
 */

void ft_push_back(t_file **start, t_file *new)
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
	new->date = NULL;
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
	while ((data = readdir(rep)) != NULL)
	{
		if ((arg[2] && data->d_name[0] == '.') || data->d_name[0] != '.')
		{
			file = ft_new_elem(data->d_name);
			ft_push_back(&lst, file);
		}
	}
	ft_show_list(lst);
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
	while (i < (argc))
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
