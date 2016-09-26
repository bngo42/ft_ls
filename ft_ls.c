/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:56:54 by bngo              #+#    #+#             */
/*   Updated: 2016/09/26 13:31:36 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
t_file	*ft_push_back(t_file *lst, t_file *elem)
{
	return (lst);
}

t_file	*ft_new_elem(char *name)
{
	t_file *new;

	if(!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->name = name;
	new->date_create = 0;
	new->next = NULL;
	return (new);
}
*/

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
	while (argv[++i] && !ft_strstr((*result), "--"))
	{
		j = 0;
		if (argv[i][0] != '-')
			return (-1);//Pas de '-' avant les options
		while (argv[i][j])
		{
			if (argv[i][j] != '-' && !ft_strchr(flag, argv[i][j]))
			{
				ft_putendl("cond2");
				return (-1);// Options non supporte
			}
			else if (argv[i][j] == '-' && j > 0 && (argv[i][j - 1] != ' ' && argv[i][j - 1] != '-'))
			{
				ft_putendl("cond3");// Pas d'espace avant '-'
				return (-1);
			}
			else
			{
				ft_putendl("cond4");
				arg[0] = argv[i][j];
				(*result) = ft_strjoin((*result), arg);
			}
			j++;
		}
		ft_strdel(&argv[i]);
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
	while (j < 5)
		ft_putnbr(arg[j++]);
	ft_putchar('\n');
	return (1);
}


int		ft_list_file(DIR *rep)
{
	struct dirent *data;

	while ((data = readdir(rep)) != NULL)
	{
		ft_putstr(data->d_name);
		ft_putchar('\n');
	}
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
	while (++i < argc)
		value[i - 1] = ft_strdup(argv[i]);
	arg = (int*)malloc(sizeof(int) * 5);
	if (!(ft_check_param(value, arg)))
		return (1);
	for(int p = 0; p < argc - 1; p++)
		printf("argv[%i] = %s\n", p, value[p]);
	i = 1;
	while (i < (argc - 1))
	{
		if (value[i] != NULL)
		{
			if(!(rep = opendir(value[i])))
				return (-1);
			ft_list_file(rep);
		}
		i++;
	}
		
	return (0);
}	
